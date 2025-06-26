#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

enum TokenType {
    PROGRAM, READ, WRITE, INTEGER, BOOLEAN, DOUBLE,
    FUNCTION, PROCEDURE, BEGIN_, END_,
    AND, ARRAY, CASE, CONST, DIV, DO, DOWNTO, ELSE_, FILE_, FOR,
    GOTO, IF_, IN, LABEL, MOD, NIL, NOT_, OF, OR, PACKED,
    RECORD, REPEAT, SET, THEN, TO, TYPE, UNTIL, WITH, VAR, WHILE_,
    IDENTIFIER, NUMBER, SYMBOL, END_OF_FILE, // SYMBOL será genérico para <, >
    OP_ASSIGN,  // :=
    OP_EQ,      // =
    OP_PLUS,    // +
    OP_MINUS,   // -
    OP_MULT,    // *
    OP_DIV,     // /
    OP_INC,     // ++
    OP_DEC,     // --
    OP_NE,      // <>
    OP_GE,      // >=
    OP_LE,      // <=
    OP_EXP,     // ^
    SEMICOLON,  // ;
    COMMA,      // ,
    LPAREN,     // (
    RPAREN,     // )
    LBRACKET,   // [
    RBRACKET,   // ]
    LBRACE,     // {
    RBRACE,     // }
    DOT,        // .
    OP_COLON    // :
};

struct Token {
    TokenType type;
    string lexema;
    int line;
    int column;
};

// Mapeamento de palavras reservadas para TokenType
unordered_map<string, TokenType> palavraReservada = {
    {"program", PROGRAM}, {"read", READ}, {"write", WRITE}, {"integer", INTEGER},
    {"boolean", BOOLEAN}, {"double", DOUBLE}, {"function", FUNCTION}, {"procedure", PROCEDURE},
    {"begin", BEGIN_}, {"end", END_}, {"and", AND}, {"array", ARRAY}, {"case", CASE},
    {"const", CONST}, {"div", DIV}, {"do", DO}, {"downto", DOWNTO}, {"else", ELSE_},
    {"file", FILE_}, {"for", FOR}, {"goto", GOTO}, {"if", IF_}, {"in", IN},
    {"label", LABEL}, {"mod", MOD}, {"nil", NIL}, {"not", NOT_}, {"of", OF},
    {"or", OR}, {"packed", PACKED}, {"record", RECORD}, {"repeat", REPEAT}, {"set", SET},
    {"then", THEN}, {"to", TO}, {"type", TYPE}, {"until", UNTIL}, {"with", WITH},
    {"var", VAR}, {"while", WHILE_}
};

// Função para ler o arquivo de entrada
vector<string> readFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        throw runtime_error("Erro ao abrir o arquivo " + filename);
    }

    string firstWord;
    file >> firstWord;

    if (firstWord != "program") {
        throw runtime_error("Arquivo deve começar com 'program'");
    }

    file.clear();
    file.seekg(0); // Volta ao início do arquivo

    vector<string> vector_lines;
    string line;

    while (getline(file, line)) {
        vector_lines.push_back(line);
    }

    file.close();
    return vector_lines;
}

// Função de análise léxica
vector<Token> Lexical(const vector<string>& lines) {
    vector<Token> tokens;
    int line_number = 1;

    for (const string& line : lines) {
        int i = 0;
        int column = 1;

        while (i < line.size()) {
            char c = line[i];

            if (isspace(c)) {
                i++;
                column++;
                continue;
            }

            // Tratamento de comentários {}
            if (c == '{') {
                while (i < line.size() && line[i] != '}') {
                    i++;
                    column++;
                }
                if (i < line.size()) { // Consome o '}'
                    i++; column++;
                }
                continue;
            }

            // Tratamento de comentários (* *)
            if (c == '(' && i + 1 < line.size() && line[i + 1] == '*') {
                i += 2; column += 2;
                while (i + 1 < line.size() && !(line[i] == '*' && line[i + 1] == ')')) {
                    i++;
                    column++;
                }
                if (i + 1 < line.size()) { // Consome o '*)'
                    i += 2; column += 2;
                }
                continue;
            }

            Token token;
            token.line = line_number;
            token.column = column;

            // Identificadores e Palavras Reservadas
            if (isalpha(c)) {
                string lexema;
                while (i < line.size() && (isalnum(line[i]) || line[i] == '_')) {
                    lexema += line[i];
                    i++;
                    column++;
                }
                token.lexema = lexema;
                token.type = palavraReservada.count(lexema) ? palavraReservada[lexema] : IDENTIFIER;
                tokens.push_back(token);
                continue;
            }

            // Números (inteiros e decimais)
            if (isdigit(c)) {
                string lexema;
                while (i < line.size() && isdigit(line[i])) {
                    lexema += line[i];
                    i++;
                    column++;
                }
                if (i < line.size() && line[i] == '.') {
                    lexema += line[i++];
                    column++;
                    while (i < line.size() && isdigit(line[i])) {
                        lexema += line[i];
                        i++;
                        column++;
                    }
                }
                token.lexema = lexema;
                token.type = NUMBER;
                tokens.push_back(token);
                continue;
            }

            // Símbolos Compostos (:=, <>, <=, >=, ++, --)
            if (i + 1 < line.size()) {
                string two_char = string(1, c) + line[i + 1];

                if (two_char == ":=") {
                    token.type = OP_ASSIGN;
                } else if (two_char == "<>") {
                    token.type = OP_NE;
                } else if (two_char == "<=") {
                    token.type = OP_LE;
                } else if (two_char == ">=") {
                    token.type = OP_GE;
                } else if (two_char == "++") {
                    token.type = OP_INC;
                } else if (two_char == "--") {
                    token.type = OP_DEC;
                } else {
                    two_char = ""; // Não é um símbolo composto de 2 caracteres
                }

                if (!two_char.empty()) {
                    token.lexema = two_char;
                    i += 2;
                    column += 2;
                    tokens.push_back(token);
                    continue;
                }
            }

            // Símbolos Simples
            switch (c) {
                case '+': token.type = OP_PLUS; token.lexema = "+"; break;
                case '-': token.type = OP_MINUS; token.lexema = "-"; break;
                case '*': token.type = OP_MULT; token.lexema = "*"; break;
                case '/': token.type = OP_DIV; token.lexema = "/"; break;
                case '^': token.type = OP_EXP; token.lexema = "^"; break;
                case '=': token.type = OP_EQ; token.lexema = "="; break;
                case ';': token.type = SEMICOLON; token.lexema = ";"; break;
                case ',': token.type = COMMA; token.lexema = ","; break;
                case '(': token.type = LPAREN; token.lexema = "("; break;
                case ')': token.type = RPAREN; token.lexema = ")"; break;
                case '[': token.type = LBRACKET; token.lexema = "["; break;
                case ']': token.type = RBRACKET; token.lexema = "]"; break;
                case '{': token.type = LBRACE; token.lexema = "{"; break; 
                case '}': token.type = RBRACE; token.lexema = "}"; break; 
                case '.': token.type = DOT; token.lexema = "."; break;
                case ':': token.type = OP_COLON; token.lexema = ":"; break;
                case '<': token.type = SYMBOL; token.lexema = "<"; break;
                case '>': token.type = SYMBOL; token.lexema = ">"; break;
                default:
                    token.type = SYMBOL;
                    token.lexema = string(1, c);
                    break;
            }

            tokens.push_back(token);
            i++;
            column++;
        }
        line_number++;
    }
    Token eofToken;
    eofToken.type = END_OF_FILE;
    eofToken.lexema = "EOF";
    eofToken.line = line_number;
    eofToken.column = 1;
    tokens.push_back(eofToken);

    return tokens;
}



vector<Token> global_tokens;
int global_currentTokenIndex = 0;

std::unordered_map<TokenType, std::string> tokenTypeToString = {
    {PROGRAM, "PROGRAM"}, {READ, "READ"}, {WRITE, "WRITE"}, {INTEGER, "INTEGER"},
    {BOOLEAN, "BOOLEAN"}, {DOUBLE, "DOUBLE"}, {FUNCTION, "FUNCTION"}, {PROCEDURE, "PROCEDURE"},
    {BEGIN_, "BEGIN"}, {END_, "END"}, {AND, "AND"}, {ARRAY, "ARRAY"}, {CASE, "CASE"},
    {CONST, "CONST"}, {DIV, "DIV"}, {DO, "DO"}, {DOWNTO, "DOWNTO"}, {ELSE_, "ELSE"},
    {FILE_, "FILE"}, {FOR, "FOR"}, {GOTO, "GOTO"}, {IF_, "IF"}, {IN, "IN"},
    {LABEL, "LABEL"}, {MOD, "MOD"}, {NIL, "NIL"}, {NOT_, "NOT"}, {OF, "OF"},
    {OR, "OR"}, {PACKED, "PACKED"}, {RECORD, "RECORD"}, {REPEAT, "REPEAT"}, {SET, "SET"},
    {THEN, "THEN"}, {TO, "TO"}, {TYPE, "TYPE"}, {UNTIL, "UNTIL"}, {WITH, "WITH"},
    {VAR, "VAR"}, {WHILE_, "WHILE"}, {IDENTIFIER, "IDENTIFIER"}, {NUMBER, "NUMBER"},
    {SYMBOL, "SYMBOL"}, {END_OF_FILE, "END_OF_FILE"},
    {OP_ASSIGN, ":="}, {OP_EQ, "="}, {OP_PLUS, "+"}, {OP_MINUS, "-"}, {OP_MULT, "*"},
    {OP_DIV, "/"}, {OP_INC, "++"}, {OP_DEC, "--"}, {OP_NE, "<>"}, {OP_GE, ">="},
    {OP_LE, "<="}, {OP_EXP, "^"}, {SEMICOLON, ";"}, {COMMA, ","}, {LPAREN, "("},
    {RPAREN, ")"}, {LBRACKET, "["}, {RBRACKET, "]"}, {LBRACE, "{"}, {RBRACE, "}"},
    {DOT, "."}, {OP_COLON, ":"}
};

std::string getTokenTypeString(TokenType type) {
    auto it = tokenTypeToString.find(type);
    if (it != tokenTypeToString.end()) {
        return it->second;
    }
    return "UNKNOWN";
}


// Protótipos das funções do parser
void match(TokenType expectedType);
void parseProgram();
void parseDeclarations();
void parseVarDeclaration();
void parseIdList();
void parseType();
void parseFunctionDeclaration();
void parseParameterList();
void parseBlock();
void parseStatements();
void parseStatement();
void parseCondition();
void parseRelationalOperator();
void parseExpression();
void parseTerm();
void parseFactor();
void parseExpressionWithAssignment();

// Lógica para consumir um token do tipo esperado
void match(TokenType expectedType) {
    if (global_currentTokenIndex < global_tokens.size()) {
        Token currentToken = global_tokens[global_currentTokenIndex];
        // O léxico pode retornar SYMBOL para < e >, então o match deve ser flexível
        bool typeMatch = (currentToken.type == expectedType);

        if (typeMatch) {
            global_currentTokenIndex++;
        } else {
            std::cerr << "Erro sintático na linha " << currentToken.line
                      << ", coluna " << currentToken.column << ": Esperado "
                      << getTokenTypeString(expectedType) << " ('" << getTokenTypeString(expectedType) << "')" 
                      << " mas encontrado " << currentToken.lexema << " (Tipo: "
                      << getTokenTypeString(currentToken.type) << ")" << std::endl;
            exit(1);
        }
    } else {
        std::cerr << "Erro sintático: Fim inesperado do arquivo. Esperado "
                  << getTokenTypeString(expectedType) << std::endl;
        exit(1); 
    }
}



void parseProgram() {
    match(PROGRAM);
    match(IDENTIFIER);
    match(SEMICOLON);
    parseDeclarations();
    parseBlock();
    match(DOT);
    std::cout << "Análise sintática concluída com sucesso!" << std::endl;
}

void parseDeclarations() {
    while (global_currentTokenIndex < global_tokens.size() &&
           (global_tokens[global_currentTokenIndex].type == VAR || global_tokens[global_currentTokenIndex].type == FUNCTION)) {
        if (global_tokens[global_currentTokenIndex].type == VAR) {
            parseVarDeclaration();
        } else if (global_tokens[global_currentTokenIndex].type == FUNCTION) {
            parseFunctionDeclaration();
        }
    }
}

void parseVarDeclaration() {
    match(VAR);
    parseIdList();
    match(OP_COLON);
    match(INTEGER); // Apenas integer no input.txt
    match(SEMICOLON);
}

void parseIdList() {
    match(IDENTIFIER);
    while (global_currentTokenIndex < global_tokens.size() && global_tokens[global_currentTokenIndex].type == COMMA) {
        match(COMMA);
        match(IDENTIFIER);
    }
}

void parseType() {
    match(INTEGER); // Simplificado para INTEGER baseado no input.txt
}

void parseFunctionDeclaration() {
    match(FUNCTION);
    match(IDENTIFIER);
    match(LPAREN);
    parseParameterList();
    match(RPAREN);
    match(OP_COLON);
    parseType();
    match(SEMICOLON);
    parseBlock();
    match(SEMICOLON);
}

void parseParameterList() {
    match(IDENTIFIER);
    match(OP_COLON);
    parseType();

}

void parseBlock() {
    match(BEGIN_);
    parseStatements();
    match(END_);
}

void parseStatements() {
    // Verifica se o próximo token é um início de comando ou um bloco aninhado
    while (global_currentTokenIndex < global_tokens.size() &&
           (global_tokens[global_currentTokenIndex].type == READ ||
            global_tokens[global_currentTokenIndex].type == WRITE ||
            global_tokens[global_currentTokenIndex].type == IF_ ||
            global_tokens[global_currentTokenIndex].type == IDENTIFIER ||
            global_tokens[global_currentTokenIndex].type == BEGIN_)) // Adicionado BEGIN_ para blocos aninhados
    {
        parseStatement();
        while (global_currentTokenIndex < global_tokens.size() && global_tokens[global_currentTokenIndex].type == SEMICOLON) {
            match(SEMICOLON);
        }
    }
}


void parseStatement() {
    TokenType currentType = global_tokens[global_currentTokenIndex].type;
    if (currentType == READ) {
        match(READ);
        match(LPAREN);
        match(IDENTIFIER);
        match(RPAREN);
    } else if (currentType == WRITE) {
        match(WRITE);
        match(LPAREN);
        parseExpression();
        match(RPAREN);
    } else if (currentType == IF_) {
        match(IF_);
        match(LPAREN); // Para (n<1)
        parseCondition();
        match(RPAREN); // Para (n<1)
        match(THEN);
        parseStatement();
        if (global_currentTokenIndex < global_tokens.size() && global_tokens[global_currentTokenIndex].type == ELSE_) {
            match(ELSE_);
            parseStatement();
        }
    } else if (currentType == IDENTIFIER) {
        // Pode ser atribuição normal (:=) ou a atribuição condicional (>=) do exemplo
        std::string nextLexema = (global_currentTokenIndex + 1 < global_tokens.size()) ? global_tokens[global_currentTokenIndex+1].lexema : "";
        if (nextLexema == ":=" || nextLexema == ">=") {
            parseExpressionWithAssignment();
        } else {
            // Se for um identificador sozinho (como "teste1234;" no input.txt)
            match(IDENTIFIER);
        }
    } else if (currentType == BEGIN_) { // Para blocos aninhados
        parseBlock();
    }
    else {
        std::cerr << "Erro sintático na linha " << global_tokens[global_currentTokenIndex].line
                  << ", coluna " << global_tokens[global_currentTokenIndex].column << ": Comando inválido: "
                  << global_tokens[global_currentTokenIndex].lexema << std::endl;
        exit(1);
    }
}

// Adicionado para suportar a linha "fatorial >= n * fatorial(n-1)"
void parseExpressionWithAssignment() {
    match(IDENTIFIER);
    if (global_tokens[global_currentTokenIndex].type == OP_ASSIGN) {
        match(OP_ASSIGN);
    } else if (global_tokens[global_currentTokenIndex].type == OP_GE) {
        match(OP_GE); // Para o caso do fatorial >=
    } else {
        std::cerr << "Erro sintático na linha " << global_tokens[global_currentTokenIndex].line
                  << ", coluna " << global_tokens[global_currentTokenIndex].column << ": Esperado := ou >=, mas encontrado "
                  << global_tokens[global_currentTokenIndex].lexema << std::endl;
        exit(1);
    }
    parseExpression();
}


void parseCondition() {
    parseExpression();
    parseRelationalOperator();
    parseExpression();
}

void parseRelationalOperator() {
    TokenType currentType = global_tokens[global_currentTokenIndex].type;
    // O léxico retorna SYMBOL para < e >, então precisamos verificar o lexema também
    if (currentType == OP_EQ || currentType == OP_NE ||
        currentType == OP_LE || currentType == OP_GE ||
        (currentType == SYMBOL && (global_tokens[global_currentTokenIndex].lexema == "<" || global_tokens[global_currentTokenIndex].lexema == ">"))) {
        match(currentType); // Match com o tipo específico ou SYMBOL para <, >
    } else {
        std::cerr << "Erro sintático na linha " << global_tokens[global_currentTokenIndex].line
                  << ", coluna " << global_tokens[global_currentTokenIndex].column << ": Operador relacional inválido: "
                  << global_tokens[global_currentTokenIndex].lexema << std::endl;
        exit(1);
    }
}

void parseExpression() {
    parseTerm();
    while (global_currentTokenIndex < global_tokens.size() &&
           (global_tokens[global_currentTokenIndex].type == OP_PLUS || global_tokens[global_currentTokenIndex].type == OP_MINUS)) {
        match(global_tokens[global_currentTokenIndex].type);
        parseTerm();
    }
}

void parseTerm() {
    parseFactor();
    while (global_currentTokenIndex < global_tokens.size() &&
           (global_tokens[global_currentTokenIndex].type == OP_MULT || global_tokens[global_currentTokenIndex].type == OP_DIV)) {
        match(global_tokens[global_currentTokenIndex].type);
        parseFactor();
    }
}

void parseFactor() {
    TokenType currentType = global_tokens[global_currentTokenIndex].type;
    if (currentType == IDENTIFIER) {
        if (global_currentTokenIndex + 1 < global_tokens.size() && global_tokens[global_currentTokenIndex + 1].type == LPAREN) {
            match(IDENTIFIER);
            match(LPAREN);
            parseExpression();
            match(RPAREN);
        } else {
            match(IDENTIFIER);
        }
    } else if (currentType == NUMBER) {
        match(NUMBER);
    } else if (currentType == LPAREN) {
        match(LPAREN);
        parseExpression();
        match(RPAREN);
    } else {
        std::cerr << "Erro sintático na linha " << global_tokens[global_currentTokenIndex].line
                  << ", coluna " << global_tokens[global_currentTokenIndex].column << ": Fator inválido: "
                  << global_tokens[global_currentTokenIndex].lexema << std::endl;
        exit(1);
    }
}


int main() {
    try {

        vector<string> lines = readFile("input.txt");
        global_tokens = Lexical(lines);
        parseProgram();

    } catch (const std::runtime_error& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}