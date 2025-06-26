//lexico.cpp
#include "common_types.h" // Inclui as definições comuns de TokenType e Token
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <string>
#include <cctype> // Para isalpha, isdigit

// Mapa de palavras reservadas (usado para classificar identificadores)
std::unordered_map<std::string, TokenType> palavraReservada = {
    {"program", PROGRAM_KW}, {"read", READ_KW}, {"write", WRITE_KW}, {"integer", INTEGER_TYPE_KW},
    {"boolean", BOOLEAN_TYPE_KW}, {"double", DOUBLE_TYPE_KW}, {"function", FUNCTION_KW}, {"procedure", PROCEDURE_KW},
    {"begin", BEGIN_KW}, {"end", END_KW}, {"and", AND_OP}, {"array", ARRAY_KW}, {"case", CASE_KW},
    {"const", CONST_KW}, {"div", DIV_OP}, {"do", DO_KW}, {"downto", DOWNTO_KW}, {"else", ELSE_KW},
    {"file", FILE_KW}, {"for", FOR_KW}, {"goto", GOTO_KW}, {"if", IF_KW}, {"in", IN_KW},
    {"label", LABEL_KW}, {"mod", MOD_OP}, {"nil", NIL_KW}, {"not", NOT_OP}, {"of", OF_KW},
    {"or", OR_OP}, {"packed", PACKED_KW}, {"record", RECORD_KW}, {"repeat", REPEAT_KW}, {"set", SET_KW},
    {"then", THEN_KW}, {"to", TO_KW}, {"type", TYPE_KW}, {"until", UNTIL_KW}, {"with", WITH_KW},
    {"var", VAR_KW}, {"while", WHILE_KW}
};

// Função auxiliar para classificar lexemas de símbolos, alinhado com o TokenType
TokenType getSymbolTokenType(const std::string& lexema) {
    if (lexema == ":=") return ASSIGN_OP;
    if (lexema == "=") return EQUAL_OP;
    if (lexema == "+") return PLUS_OP;
    if (lexema == "-") return MINUS_OP;
    if (lexema == "*") return MULTIPLY_OP;
    if (lexema == "/") return DIVIDE_OP;
    if (lexema == "++") return INCREMENT_OP;
    if (lexema == "--") return DECREMENT_OP;
    if (lexema == "<>") return NOT_EQUAL_OP;
    if (lexema == ">=") return GREATER_EQUAL_OP;
    if (lexema == "<=") return LESS_EQUAL_OP;
    if (lexema == "^") return EXPONENT_OP;
    if (lexema == ";") return SEMICOLON_CHAR;
    if (lexema == ",") return COMMA_CHAR;
    if (lexema == "(") return LPAREN_CHAR;
    if (lexema == ")") return RPAREN_CHAR;
    if (lexema == "[") return LBRACKET_CHAR;
    if (lexema == "]") return RBRACKET_CHAR;
    if (lexema == "{") return LBRACE_CHAR;
    if (lexema == "}") return RBRACE_CHAR;
    if (lexema == ".") return DOT_CHAR;
    if (lexema == ":") return COLON_CHAR;
    if (lexema == "<") return LESS_OP;
    if (lexema == ">") return GREATER_OP;
    return GENERIC_SYMBOL_TOKEN; // Para outros símbolos não mapeados explicitamente.
}


// Função Lexical agora retorna um vetor de tokens
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
            
            // Tratamento de comentários { ... }
            if (c == '{') {
                while (i < (int)line.size() && line[i] != '}') {
                    i++;
                    column++;
                }
                if (i < (int)line.size()) { // Consome '}'
                    i++; 
                    column++;  
                }
                continue;
            }
            
            // Tratamento de comentários (* ... *)
            if (c == '(' && i + 1 < (int)line.size() && line[i + 1] == '*') {
                i += 2; 
                column += 2;
                while (i + 1 < (int)line.size() && !(line[i] == '*' && line[i + 1] == ')')) {
                    i++;
                    column++;
                }
                if (i + 1 < (int)line.size()) { // Consome '*)'
                    i += 2; 
                    column += 2; 
                }
                continue;
            }

            Token token;
            token.line = line_number;
            token.column = column;

            // Identificadores e Palavras Reservadas
            if (std::isalpha(c)) {
                std::string lexema;
                while (i < (int)line.size() && (std::isalnum(line[i]) || line[i] == '_')) {
                    lexema += line[i];
                    i++;
                    column++;
                }
                token.lexema = lexema;
                if (palavraReservada.count(lexema)) {
                    token.type = palavraReservada[lexema];
                } else {
                    token.type = IDENTIFIER_TOKEN;
                }
                tokens.push_back(token);
                continue;
            }

            // Números (inteiros e com ponto flutuante)
            if (std::isdigit(c)) {
                std::string lexema;
                while (i < (int)line.size() && std::isdigit(line[i])) {
                    lexema += line[i];
                    i++;
                    column++;
                }
                if (i < (int)line.size() && line[i] == '.') {
                    lexema += line[i++];
                    column++;
                    while (i < (int)line.size() && std::isdigit(line[i])) {
                        lexema += line[i];
                        i++;
                        column++;
                    }
                }
                token.lexema = lexema;
                token.type = NUMBER_TOKEN;
                tokens.push_back(token);
                continue;
            }

            // Operadores Compostos (2 caracteres)
            if (i + 1 < (int)line.size()) {
                std::string two_char_op = std::string(1, c) + line[i + 1];
                TokenType op_type = getSymbolTokenType(two_char_op);
                if (op_type != GENERIC_SYMBOL_TOKEN) { // Se é um operador composto conhecido
                    token.type = op_type;
                    token.lexema = two_char_op;
                    i += 2;
                    column += 2;
                    tokens.push_back(token);
                    continue;
                }
            }

            // Operadores e Símbolos Simples (1 caractere)
            TokenType simple_op_type = getSymbolTokenType(std::string(1, c));
            if (simple_op_type != GENERIC_SYMBOL_TOKEN) { // Se é um operador simples conhecido
                token.type = simple_op_type;
                token.lexema = std::string(1, c);
                i++;
                column++;
                tokens.push_back(token);
                continue;
            }

            // Se chegou aqui, é um caractere não reconhecido
            // Pode ser um erro ou um símbolo genérico.
            // Para simplificação, tratamos como GENERIC_SYMBOL_TOKEN.
            token.type = GENERIC_SYMBOL_TOKEN;
            token.lexema = std::string(1, c);
            tokens.push_back(token);
            i++;
            column++;
        }
        line_number++;
    }
    // Adiciona um token de FIM_DE_ARQUIVO no final da lista.
    tokens.push_back({END_OF_FILE_TOKEN, "EOF", line_number, 1});
    return tokens;
}

// A função main pode ser mantida para testar o léxico isoladamente
int main() {
    using namespace std;

    // Função readFile para ler o input.txt (copiada do lexico.cpp original)
    // Se você já tem essa função em um arquivo separado, pode incluí-la.
    // Aqui, ela está incluída para autonomia deste arquivo de teste.
    auto readFile = [](const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("Erro ao abrir o arquivo " + filename);
        }
        vector<string> vector_lines;
        string line;
        while (getline(file, line)) {
            vector_lines.push_back(line);
        }
        file.close();
        return vector_lines;
    };

    try {
        vector<string> lines = readFile("input.txt");
        vector<Token> tokens_result = Lexical(lines);

        // Opcional: imprimir os tokens para o console para verificar
        // Isso simula o output.txt, mas não o cria como arquivo.
        cout << "Tokens gerados pelo lexico:\n";
        for (const Token& token : tokens_result) {
            cout << "Lexema: \"" << token.lexema << "\" || Tipo: " << token.type 
                 << " || Linha: " << token.line << " || Coluna: " << token.column << "\n";
        }
    } catch (const runtime_error& e) {
        cerr << "Erro no lexico: " << e.what() << "\n";
        return 1;
    }
    return 0;
}