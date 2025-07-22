#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
#include <stack> 

enum TokenType {
    PROGRAM, READ, WRITE, INTEGER, BOOLEAN, DOUBLE,
    FUNCTION, PROCEDURE, BEGIN_, END_,
    AND, ARRAY, CASE, CONST, DIV, DO, DOWNTO, ELSE_, FILE_, FOR,
    GOTO, IF_, IN, LABEL, MOD, NIL, NOT_, OF, OR, PACKED,
    RECORD, REPEAT, SET, THEN, TO, TYPE, UNTIL, WITH, VAR, WHILE_,
    IDENTIFIER, NUMBER, SYMBOL, END_OF_FILE,
    OP_ASSIGN,
    OP_EQ,
    OP_PLUS,
    OP_MINUS,
    OP_MULT,
    OP_DIV,
    OP_INC,
    OP_DEC,
    OP_NE,
    OP_GE,
    OP_LE,
    OP_EXP,
    SEMICOLON,
    COMMA,
    LPAREN,
    RPAREN,
    LBRACKET,
    RBRACKET,
    LBRACE,
    RBRACE,
    DOT,
    OP_COLON,
    LITERAL_TRUE,
    LITERAL_FALSE
};

struct Token {
    TokenType type;
    std::string lexema;
    int line;
    int column;
};

struct SymbolInfo {
    TokenType type;
    bool is_function;
    std::vector<TokenType> param_types;
    TokenType return_type;
};

std::vector<std::unordered_map<std::string, SymbolInfo>> symbolTableStack;

// Variável global para rastrear a função sendo analisada atualmente
SymbolInfo* current_parsing_function_symbol = nullptr;


std::unordered_map<std::string, TokenType> palavraReservada = {
    {"program", PROGRAM}, {"read", READ}, {"write", WRITE}, {"integer", INTEGER},
    {"boolean", BOOLEAN}, {"double", DOUBLE}, {"function", FUNCTION}, {"procedure", PROCEDURE},
    {"begin", BEGIN_}, {"end", END_}, {"and", AND}, {"array", ARRAY}, {"case", CASE},
    {"const", CONST}, {"div", DIV}, {"do", DO}, {"downto", DOWNTO}, {"else", ELSE_},
    {"file", FILE_}, {"for", FOR}, {"goto", GOTO}, {"if", IF_}, {"in", IN},
    {"label", LABEL}, {"mod", MOD}, {"nil", NIL}, {"not", NOT_}, {"of", OF},
    {"or", OR}, {"packed", PACKED}, {"record", RECORD}, {"repeat", REPEAT}, {"set", SET},
    {"then", THEN}, {"to", TO}, {"type", TYPE}, {"until", UNTIL}, {"with", WITH},
    {"var", VAR}, {"while", WHILE_},
    {"true", LITERAL_TRUE}, {"false", LITERAL_FALSE}
};

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
    {DOT, "."}, {OP_COLON, ":"},
    {LITERAL_TRUE, "TRUE_LITERAL"}, {LITERAL_FALSE, "FALSE_LITERAL"}
};

std::string getTokenTypeString(TokenType type) {
    auto it = tokenTypeToString.find(type);
    if (it != tokenTypeToString.end()) {
        return it->second;
    }
    return "UNKNOWN_TOKEN_TYPE";
}

std::vector<std::string> readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Erro ao abrir o arquivo " + filename);
    }
    std::vector<std::string> vector_lines;
    std::string line;
    while (getline(file, line)) {
        vector_lines.push_back(line);
    }
    file.close();
    return vector_lines;
}

std::vector<Token> Lexical(const std::vector<std::string>& lines) {
    std::vector<Token> tokens;
    int line_number = 1;
    for (const std::string& line : lines) {
        int i = 0;
        int column = 1;
        while (i < (int)line.size()) {
            char c = line[i];
            if (std::isspace(c)) {
                i++;
                column++;
                continue;
            }
            if (c == '{') {
                while (i < (int)line.size() && line[i] != '}') {
                    i++;
                    column++;
                }
                if (i < (int)line.size()) {
                    i++;
                    column++;
                }
                continue;
            }
            if (c == '(' && i + 1 < (int)line.size() && line[i + 1] == '*') {
                i += 2;
                column += 2;
                while (i + 1 < (int)line.size() && !(line[i] == '*' && line[i + 1] == ')')) {
                    i++;
                    column++;
                }
                if (i + 1 < (int)line.size()) {
                    i += 2;
                    column += 2;
                }
                continue;
            }
            Token token;
            token.line = line_number;
            token.column = column;
            if (std::isalpha(c)) {
                std::string lexema;
                while (i < (int)line.size() && (std::isalnum(line[i]) || line[i] == '_')) {
                    lexema += line[i];
                    i++;
                    column++;
                }
                token.lexema = lexema;
                std::string lower_lexema = lexema;
                for (char &lc : lower_lexema) {
                    lc = std::tolower(lc);
                }
                if (palavraReservada.count(lower_lexema)) {
                    token.type = palavraReservada[lower_lexema];
                } else {
                    token.type = IDENTIFIER;
                }
                tokens.push_back(token);
                continue;
            }
            if (std::isdigit(c)) {
                std::string lexema;
                bool is_double = false;
                while (i < (int)line.size() && std::isdigit(line[i])) {
                    lexema += line[i];
                    i++;
                    column++;
                }
                if (i < (int)line.size() && line[i] == '.') {
                    is_double = true;
                    lexema += line[i++];
                    column++;
                    while (i < (int)line.size() && std::isdigit(line[i])) {
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
            if (i + 1 < (int)line.size()) {
                std::string two_char_op = std::string(1, c) + line[i + 1];
                if (two_char_op == ":=") {
                    token.type = OP_ASSIGN;
                } else if (two_char_op == "<>") {
                    token.type = OP_NE;
                } else if (two_char_op == "<=") {
                    token.type = OP_LE;
                } else if (two_char_op == ">=") {
                    token.type = OP_GE;
                } else if (two_char_op == "++") {
                    token.type = OP_INC;
                } else if (two_char_op == "--") {
                    token.type = OP_DEC;
                } else {
                    two_char_op = "";
                }
                if (!two_char_op.empty()) {
                    token.lexema = two_char_op;
                    i += 2;
                    column += 2;
                    tokens.push_back(token);
                    continue;
                }
            }
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
                    token.lexema = std::string(1, c);
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

std::vector<Token> global_tokens;
int global_currentTokenIndex = 0;

void match(TokenType expectedType);
void parseProgram();
void parseDeclarations();
void parseVarDeclaration();
void parseIdList(TokenType var_type);
TokenType parseType();
void parseFunctionDeclaration();
void parseParameterList(std::vector<TokenType>& param_types);
void parseBlock();
void parseStatements();
TokenType parseStatement();
TokenType parseCondition();
void parseRelationalOperator();
TokenType parseExpression();
TokenType parseTerm();
TokenType parseFactor();

// Funções auxiliares para reportar erros de forma padronizada
void semanticError(const Token& token, const std::string& message) {
    std::cerr << "Erro semântico na linha " << token.line
              << ", coluna " << token.column << ": " << message << std::endl;
    exit(1);
}

void syntacticError(const Token& token, TokenType expectedType) {
    std::cerr << "Erro sintático na linha " << token.line
              << ", coluna " << token.column << ": Esperado '"
              << getTokenTypeString(expectedType) << "', encontrado '"
              << token.lexema << "' (Tipo: " << getTokenTypeString(token.type) << ")." << std::endl;
    exit(1);
}

void syntacticErrorEOF(TokenType expectedType, int line, int column) {
    std::cerr << "Erro sintático: Fim inesperado do arquivo na linha " << line
              << ", coluna " << column << ". Esperado '"
              << getTokenTypeString(expectedType) << "'." << std::endl;
    exit(1);
}

// Funções para gerenciamento de escopo
void pushScope() {
    symbolTableStack.emplace_back();
}

void popScope() {
    if (!symbolTableStack.empty()) {
        symbolTableStack.pop_back();
    }
}

// Procura por um símbolo em todos os escopos, do mais interno para o mais externo
SymbolInfo* findSymbol(const std::string& name) {
    for (auto it = symbolTableStack.rbegin(); it != symbolTableStack.rend(); ++it) {
        if (it->count(name)) {
            return &(*it)[name];
        }
    }
    return nullptr;
}

// Adiciona um símbolo ao escopo atual (topo da pilha)
void addSymbol(const std::string& name, const SymbolInfo& info, int line, int column) {
    if (symbolTableStack.empty()) {
        semanticError(Token{IDENTIFIER, name, line, column}, "Nenhum escopo ativo para adicionar símbolo '" + name + "'.");
    }
    // Verifica redeclaração apenas no escopo atual
    if (symbolTableStack.back().count(name)) {
        semanticError(Token{IDENTIFIER, name, line, column}, "Identificador '" + name + "' já declarado no escopo atual.");
    }
    symbolTableStack.back()[name] = info;
}

// Função para Promoção de Tipos em Operações Aritméticas/Lógicas
TokenType getUnifiedType(TokenType type1, TokenType type2, int line, int column) {
    if (type1 == DOUBLE || type2 == DOUBLE) {
        if (type1 == BOOLEAN || type2 == BOOLEAN) {
             semanticError(Token{SYMBOL, "", line, column}, "Operação entre tipos incompatíveis: " + getTokenTypeString(type1) + " e " + getTokenTypeString(type2) + ".");
        }
        return DOUBLE;
    }
    if (type1 == INTEGER && type2 == INTEGER) {
        return INTEGER;
    }
    if (type1 == BOOLEAN && type2 == BOOLEAN) {
        return BOOLEAN;
    }

    semanticError(Token{SYMBOL, "", line, column}, "Operação com tipos incompatíveis: " + getTokenTypeString(type1) + " e " + getTokenTypeString(type2) + ".");
    return PROGRAM; // Retorno dummy
}


void match(TokenType expectedType) {
    if (global_currentTokenIndex < global_tokens.size()) {
        Token currentToken = global_tokens[global_currentTokenIndex];
        bool typeMatch = (currentToken.type == expectedType);
        
        if (typeMatch) {
            global_currentTokenIndex++;
        } else {
            syntacticError(currentToken, expectedType);
        }
    } else {
        syntacticErrorEOF(expectedType, global_tokens.back().line, global_tokens.back().column + 1);
    }
}

void parseProgram() {
    pushScope(); // Inicia o escopo global
    
    match(PROGRAM);
    std::string program_name = global_tokens[global_currentTokenIndex].lexema;
    
    addSymbol(program_name, {PROGRAM, false, {}, PROGRAM}, 
              global_tokens[global_currentTokenIndex].line, global_tokens[global_currentTokenIndex].column);
    
    match(IDENTIFIER);
    match(SEMICOLON);

    parseDeclarations();
    parseBlock();
    match(DOT);
    
    popScope(); // Sai do escopo global
    std::cout << "Análise sintática e semântica concluída com sucesso!" << std::endl;
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
    std::vector<std::string> ids;
    ids.push_back(global_tokens[global_currentTokenIndex].lexema);
    match(IDENTIFIER);
    while (global_currentTokenIndex < global_tokens.size() && global_tokens[global_currentTokenIndex].type == COMMA) {
        match(COMMA);
        ids.push_back(global_tokens[global_currentTokenIndex].lexema);
        match(IDENTIFIER);
    }
    match(OP_COLON);
    TokenType var_type = parseType();
    
    for (const std::string& id : ids) {
        addSymbol(id, {var_type, false, {}, INTEGER},
                  global_tokens[global_currentTokenIndex].line, global_tokens[global_currentTokenIndex].column);
    }
    match(SEMICOLON);
}

TokenType parseType() {
    TokenType currentType = global_tokens[global_currentTokenIndex].type;
    if (currentType == INTEGER || currentType == BOOLEAN || currentType == DOUBLE) {
        match(currentType);
        return currentType;
    } else {
        syntacticError(global_tokens[global_currentTokenIndex], currentType);
    }
    return PROGRAM; // Retorno dummy
}

void parseFunctionDeclaration() {
    match(FUNCTION);
    std::string func_name = global_tokens[global_currentTokenIndex].lexema;
    
    if (findSymbol(func_name) != nullptr) {
        semanticError(global_tokens[global_currentTokenIndex], "Função '" + func_name + "' já declarada.");
    }

    match(IDENTIFIER);

    SymbolInfo func_info;
    func_info.type = FUNCTION;
    func_info.is_function = true;

    match(LPAREN);
    pushScope(); // Abre um novo escopo para os parâmetros da função

    std::vector<TokenType> param_types;
    if (global_tokens[global_currentTokenIndex].type == IDENTIFIER) {
        parseParameterList(param_types);
    }
    match(RPAREN);
    match(OP_COLON);
    func_info.return_type = parseType();
    func_info.param_types = param_types;

    if (symbolTableStack.empty()) { 
        semanticError(global_tokens[global_currentTokenIndex], "Erro interno: Escopo global não inicializado para declarar função.");
    }
    // Adiciona/Atualiza a função no escopo global (primeiro elemento da pilha)
    symbolTableStack[0][func_name] = func_info;

    // Define a função atual para permitir a atribuição ao seu nome
    current_parsing_function_symbol = &symbolTableStack[0][func_name]; 

    match(SEMICOLON);
    parseBlock(); // O corpo da função é parseado dentro do novo escopo
    match(SEMICOLON);

    popScope(); // Sai do escopo da função
    current_parsing_function_symbol = nullptr; // Reseta a função atual
}

void parseParameterList(std::vector<TokenType>& param_types) {
    std::string id_name = global_tokens[global_currentTokenIndex].lexema;
    match(IDENTIFIER);
    match(OP_COLON);
    TokenType param_type = parseType();
    param_types.push_back(param_type);
    addSymbol(id_name, {param_type, false, {}, INTEGER},
              global_tokens[global_currentTokenIndex].line, global_tokens[global_currentTokenIndex].column);

    while (global_currentTokenIndex < global_tokens.size() && global_tokens[global_currentTokenIndex].type == SEMICOLON) {
        match(SEMICOLON);
        id_name = global_tokens[global_currentTokenIndex].lexema;
        match(IDENTIFIER);
        match(OP_COLON);
        param_type = parseType();
        param_types.push_back(param_type);
        addSymbol(id_name, {param_type, false, {}, INTEGER},
                  global_tokens[global_currentTokenIndex].line, global_tokens[global_currentTokenIndex].column);
    }
}

void parseBlock() {
    pushScope(); // Abre um novo escopo para o bloco
    match(BEGIN_);
    parseStatements();
    match(END_);
    popScope(); // Sai do escopo do bloco
}

void parseStatements() {
    while (global_currentTokenIndex < global_tokens.size() &&
           (global_tokens[global_currentTokenIndex].type == READ ||
            global_tokens[global_currentTokenIndex].type == WRITE ||
            global_tokens[global_currentTokenIndex].type == IF_ ||
            global_tokens[global_currentTokenIndex].type == IDENTIFIER ||
            global_tokens[global_currentTokenIndex].type == BEGIN_))
    {
        parseStatement();
        while (global_currentTokenIndex < global_tokens.size() && global_tokens[global_currentTokenIndex].type == SEMICOLON) {
            match(SEMICOLON);
        }
    }
}

TokenType parseStatement() {
    TokenType currentType = global_tokens[global_currentTokenIndex].type;
    TokenType stmt_type = INTEGER; 
    
    if (currentType == READ) {
        match(READ);
        match(LPAREN);
        std::string id_name = global_tokens[global_currentTokenIndex].lexema;
        
        SymbolInfo* symbol = findSymbol(id_name);
        if (symbol == nullptr) {
            semanticError(global_tokens[global_currentTokenIndex], "Identificador '" + id_name + "' não declarado.");
        }
        if (symbol->is_function) {
            semanticError(global_tokens[global_currentTokenIndex], "Não é possível ler diretamente uma função '" + id_name + "'.");
        }
        stmt_type = symbol->type;
        match(IDENTIFIER);
        match(RPAREN);
    } else if (currentType == WRITE) {
        match(WRITE);
        match(LPAREN);
        stmt_type = parseExpression();
        match(RPAREN);
    } else if (currentType == IF_) {
        match(IF_);
        match(LPAREN);
        TokenType cond_type = parseCondition();
        if (cond_type != BOOLEAN && cond_type != INTEGER && cond_type != DOUBLE) { 
            semanticError(global_tokens[global_currentTokenIndex], "Condição IF espera tipo booleano ou numérico, mas encontrou " + getTokenTypeString(cond_type) + ".");
        }
        match(RPAREN);
        match(THEN);
        parseStatement();
        if (global_currentTokenIndex < global_tokens.size() && global_tokens[global_currentTokenIndex].type == ELSE_) {
            match(ELSE_);
            parseStatement();
        }
        stmt_type = INTEGER;
    } else if (currentType == IDENTIFIER) {
        std::string id_name = global_tokens[global_currentTokenIndex].lexema;
        Token next_token = (global_currentTokenIndex + 1 < global_tokens.size()) ? global_tokens[global_currentTokenIndex+1] : Token{END_OF_FILE, "EOF", global_tokens.back().line, global_tokens.back().column + 1};
        
        if (next_token.type == OP_ASSIGN || next_token.type == OP_GE) {
            SymbolInfo* symbol = findSymbol(id_name);
            if (symbol == nullptr) {
                semanticError(global_tokens[global_currentTokenIndex], "Identificador '" + id_name + "' não declarado.");
            }
            // Permite atribuição ao nome da função se estiver dentro do corpo dela.
            if (symbol->is_function && symbol != current_parsing_function_symbol) {
                 semanticError(global_tokens[global_currentTokenIndex], "Atribuição inválida para a função '" + id_name + "'. Atribuição ao nome da função só é permitida dentro de seu próprio corpo para definir o valor de retorno.");
            }

            match(IDENTIFIER);
            TokenType assign_op = global_tokens[global_currentTokenIndex].type;
            match(assign_op);
            TokenType rhs_type = parseExpression();

            TokenType lhs_type = symbol->type;
            if (lhs_type != rhs_type) { 
                // Se a atribuição é para o nome da função (current_parsing_function_symbol), 
                // o tipo do LHS deve ser o return_type da função.
                TokenType expected_lhs_type = (symbol == current_parsing_function_symbol) ? symbol->return_type : lhs_type;

                if (expected_lhs_type != rhs_type) {
                    semanticError(global_tokens[global_currentTokenIndex], "Incompatibilidade de tipos na atribuição. Esperado '" + getTokenTypeString(expected_lhs_type) + "', encontrado '" + getTokenTypeString(rhs_type) + "'.");
                }
            }
            stmt_type = lhs_type;
        } else if (next_token.type == LPAREN) {
            stmt_type = parseFactor();
        } else {
            SymbolInfo* symbol = findSymbol(id_name);
            if (symbol == nullptr) {
                semanticError(global_tokens[global_currentTokenIndex], "Identificador '" + id_name + "' não declarado.");
            }
            if (!symbol->is_function && symbol->type != PROGRAM) {
                semanticError(global_tokens[global_currentTokenIndex], "Identificador '" + id_name + "' avulso. Esperado atribuição ou chamada de função/procedimento.");
            }
            if (symbol->is_function && symbol->param_types.empty()) {
                semanticError(global_tokens[global_currentTokenIndex], "Chamada de função '" + id_name + "' requer parênteses, mesmo sem argumentos.");
            }
            
            syntacticError(global_tokens[global_currentTokenIndex], IDENTIFIER);
        }
    } else if (currentType == BEGIN_) {
        parseBlock();
        stmt_type = INTEGER; 
    }
    else {
        syntacticError(global_tokens[global_currentTokenIndex], currentType);
    }
    return stmt_type;
}

TokenType parseCondition() {
    TokenType left_type = parseExpression();
    parseRelationalOperator();
    TokenType right_type = parseExpression();
    
    TokenType unified_type = getUnifiedType(left_type, right_type, 
                                            global_tokens[global_currentTokenIndex].line, 
                                            global_tokens[global_currentTokenIndex].column);
    
    if (unified_type != INTEGER && unified_type != BOOLEAN && unified_type != DOUBLE) {
        semanticError(global_tokens[global_currentTokenIndex], "Tipos incompatíveis na condição. Tipos encontrados: '" + getTokenTypeString(left_type) + "' vs '" + getTokenTypeString(right_type) + "'.");
    }
    return BOOLEAN;
}

void parseRelationalOperator() {
    TokenType currentType = global_tokens[global_currentTokenIndex].type;
    if (currentType == OP_EQ || currentType == OP_NE ||
        currentType == OP_LE || currentType == OP_GE ||
        (currentType == SYMBOL && (global_tokens[global_currentTokenIndex].lexema == "<" || global_tokens[global_currentTokenIndex].lexema == ">"))) {
        match(currentType);
    } else {
        syntacticError(global_tokens[global_currentTokenIndex], SYMBOL);
    }
}

TokenType parseExpression() {
    TokenType left_type = parseTerm();
    while (global_currentTokenIndex < global_tokens.size() &&
           (global_tokens[global_currentTokenIndex].type == OP_PLUS || global_tokens[global_currentTokenIndex].type == OP_MINUS)) {
        TokenType op_type = global_tokens[global_currentTokenIndex].type;
        match(op_type);
        TokenType right_type = parseTerm();
        
        left_type = getUnifiedType(left_type, right_type, 
                                   global_tokens[global_currentTokenIndex].line, 
                                   global_tokens[global_currentTokenIndex].column);
    }
    return left_type;
}

TokenType parseTerm() {
    TokenType left_type = parseFactor();
    while (global_currentTokenIndex < global_tokens.size() &&
           (global_tokens[global_currentTokenIndex].type == OP_MULT || global_tokens[global_currentTokenIndex].type == OP_DIV)) {
        TokenType op_type = global_tokens[global_currentTokenIndex].type;
        match(op_type);
        TokenType right_type = parseFactor();
        
        left_type = getUnifiedType(left_type, right_type, 
                                   global_tokens[global_currentTokenIndex].line, 
                                   global_tokens[global_currentTokenIndex].column);
    }
    return left_type;
}

TokenType parseFactor() {
    TokenType currentType = global_tokens[global_currentTokenIndex].type;
    TokenType factor_type = INTEGER;

    if (currentType == IDENTIFIER) {
        std::string id_name = global_tokens[global_currentTokenIndex].lexema;
        
        SymbolInfo* symbol = findSymbol(id_name);
        if (symbol == nullptr) {
            semanticError(global_tokens[global_currentTokenIndex], "Identificador '" + id_name + "' não declarado.");
        }
        
        if (global_currentTokenIndex + 1 < global_tokens.size() && global_tokens[global_currentTokenIndex + 1].type == LPAREN) {
            if (!symbol->is_function) {
                semanticError(global_tokens[global_currentTokenIndex], "Identificador '" + id_name + "' não é uma função.");
            }
            match(IDENTIFIER);
            match(LPAREN);
            
            std::vector<TokenType> actual_param_types;
            if (global_tokens[global_currentTokenIndex].type != RPAREN) {
                actual_param_types.push_back(parseExpression());
                while (global_currentTokenIndex < global_tokens.size() && global_tokens[global_currentTokenIndex].type == COMMA) {
                    match(COMMA);
                    actual_param_types.push_back(parseExpression());
                }
            }
            match(RPAREN);

            if (actual_param_types.size() != symbol->param_types.size()) {
                semanticError(global_tokens[global_currentTokenIndex], "Chamada de função '" + id_name + "' com número incorreto de argumentos. Esperado " + std::to_string(symbol->param_types.size()) + " mas encontrado " + std::to_string(actual_param_types.size()) + ".");
            }
            for (size_t i = 0; i < actual_param_types.size(); ++i) {
                TokenType promoted_type = getUnifiedType(actual_param_types[i], symbol->param_types[i], 
                                                         global_tokens[global_currentTokenIndex].line, 
                                                         global_tokens[global_currentTokenIndex].column);
                if (promoted_type != symbol->param_types[i]) {
                    semanticError(global_tokens[global_currentTokenIndex], "Chamada de função '" + id_name + "' com tipo de argumento incompatível na posição " + std::to_string(i+1) + ". Esperado '" + getTokenTypeString(symbol->param_types[i]) + "' mas encontrado '" + getTokenTypeString(actual_param_types[i]) + "'.");
                }
            }
            factor_type = symbol->return_type;
        } else {
            factor_type = symbol->type;
            match(IDENTIFIER);
        }
    } else if (currentType == NUMBER) {
        if (global_tokens[global_currentTokenIndex].lexema.find('.') != std::string::npos) {
            factor_type = DOUBLE;
        } else {
            factor_type = INTEGER;
        }
        match(NUMBER);
    } else if (currentType == LPAREN) {
        match(LPAREN);
        factor_type = parseExpression();
        match(RPAREN);
    } else if (currentType == LITERAL_TRUE || currentType == LITERAL_FALSE) {
        factor_type = BOOLEAN;
        match(currentType);
    }
    else {
        syntacticError(global_tokens[global_currentTokenIndex], currentType);
    }
    return factor_type;
}

int main() {
    try {
        std::vector<std::string> lines = readFile("input.txt");
        global_tokens = Lexical(lines);
        parseProgram();
    } catch (const std::runtime_error& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return 1;
    }
}