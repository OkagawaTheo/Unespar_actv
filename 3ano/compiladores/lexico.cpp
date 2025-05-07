#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

enum TokenType {
    PROGRAM, READ, WRITE, INTEGER, BOOLEAN, DOUBLE,
    FUNCTION, PROCEDURE, BEGIN_, END_,
    AND, ARRAY, CASE, CONST, DIV, DO, DOWNTO, ELSE_, FILE_, FOR,
    GOTO, IF_, IN, LABEL, MOD, NIL, NOT_, OF, OR, PACKED,
    RECORD, REPEAT, SET, THEN, TO, TYPE, UNTIL, WITH, VAR, WHILE_,
    IDENTIFIER, NUMBER, SYMBOL, END_OF_FILE,
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
    bool isReserved = false;
};

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
    file.seekg(0);

    vector<string> vector_lines;
    string line;

    while (getline(file, line)) {
        vector_lines.push_back(line);
    }

    file.close();
    return vector_lines;
}


string tokenTypeToString(TokenType type) {
    switch (type) {
        case PROGRAM: return "PROGRAM";
        case READ: return "READ";
        case WRITE: return "WRITE";
        case INTEGER: return "INTEGER";
        case BOOLEAN: return "BOOLEAN";
        case DOUBLE: return "DOUBLE";
        case FUNCTION: return "FUNCTION";
        case PROCEDURE: return "PROCEDURE";
        case BEGIN_: return "BEGIN";
        case END_: return "END";
        case AND: return "AND";
        case ARRAY: return "ARRAY";
        case CASE: return "CASE";
        case CONST: return "CONST";
        case DIV: return "DIV";
        case DO: return "DO";
        case DOWNTO: return "DOWNTO";
        case ELSE_: return "ELSE";
        case FILE_: return "FILE";
        case FOR: return "FOR";
        case GOTO: return "GOTO";
        case IF_: return "IF";
        case IN: return "IN";
        case LABEL: return "LABEL";
        case MOD: return "MOD";
        case NIL: return "NIL";
        case NOT_: return "NOT";
        case OF: return "OF";
        case OR: return "OR";
        case PACKED: return "PACKED";
        case RECORD: return "RECORD";
        case REPEAT: return "REPEAT";
        case SET: return "SET";
        case THEN: return "THEN";
        case TO: return "TO";
        case TYPE: return "TYPE";
        case UNTIL: return "UNTIL";
        case WITH: return "WITH";
        case VAR: return "VAR";
        case WHILE_: return "WHILE";
        case IDENTIFIER: return "IDENTIFIER";
        case NUMBER: return "NUMBER";
        case SYMBOL: return "SYMBOL";
        case END_OF_FILE: return "END_OF_FILE";
        case OP_ASSIGN: return "OP_ASSIGN";
        case OP_EQ: return "OP_EQ";
        case OP_PLUS: return "OP_PLUS";
        case OP_MINUS: return "OP_MINUS";
        case OP_MULT: return "OP_MULT";
        case OP_DIV: return "OP_DIV";
        case OP_INC: return "OP_INC";
        case OP_DEC: return "OP_DEC";
        case OP_NE: return "OP_NE";
        case OP_GE: return "OP_GE";
        case OP_LE: return "OP_LE";
        case OP_EXP: return "OP_EXP";
        case SEMICOLON: return "SEMICOLON";
        case COMMA: return "COMMA";
        case LPAREN: return "LPAREN";
        case RPAREN: return "RPAREN";
        case LBRACKET: return "LBRACKET";
        case RBRACKET: return "RBRACKET";
        case LBRACE: return "LBRACE";
        case RBRACE: return "RBRACE";
        case DOT: return "DOT";
        case OP_COLON: return "OP_COLON";
        default: return "UNKNOWN";
    }
}

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

            Token token;
            token.line = line_number;
            token.column = column;

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

            if (i + 1 < line.size()) {
                string two_char = string(1, c) + line[i+1];

                if (two_char == ":=") {
                    token.type = OP_ASSIGN;
                    token.lexema = two_char;
                    i += 2;
                    column += 2;
                    tokens.push_back(token);
                    continue;
                }
                if (two_char == "<>") {
                    token.type = OP_NE;
                    token.lexema = two_char;
                    i += 2;
                    column += 2;
                    tokens.push_back(token);
                    continue;
                }
                if (two_char == "<=") {
                    token.type = OP_LE;
                    token.lexema = two_char;
                    i += 2;
                    column += 2;
                    tokens.push_back(token);
                    continue;
                }
                if (two_char == ">=") {
                    token.type = OP_GE;
                    token.lexema = two_char;
                    i += 2;
                    column += 2;
                    tokens.push_back(token);
                    continue;
                }
                if (two_char == "++") {
                    token.type = OP_INC;
                    token.lexema = two_char;
                    i += 2;
                    column += 2;
                    tokens.push_back(token);
                    continue;
                }
                if (two_char == "--") {
                    token.type = OP_DEC;
                    token.lexema = two_char;
                    i += 2;
                    column += 2;
                    tokens.push_back(token);
                    continue;
                }
            }

            switch(c) {
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

    return tokens;
}

int main() {
    vector<string> lines = readFile("input.txt");
    vector<Token> tokens = Lexical(lines);

    ofstream output("output.txt");

    for (const Token& token : tokens) {
        string info = "Token: " + token.lexema +
                      " | Tipo: " + tokenTypeToString(token.type) +
                      " (Linha " + to_string(token.line) +
                      ", Coluna " + to_string(token.column) + ")\n";

        
        output << info;
    }
    cout << "output salvo no arquivo output.txt";

    output.close();
}
