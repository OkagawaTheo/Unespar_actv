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

string getSimplifiedTokenType(TokenType type) {
    if (type >= PROGRAM && type <= WHILE_) {
        return "palavra reservada";
    }
    else if (type == IDENTIFIER) {
        return "identificador";
    }
    else if (type == NUMBER) {
        return "número";
    }
    else if (type == OP_ASSIGN || type == OP_NE || type == OP_GE || 
             type == OP_LE || type == OP_INC || type == OP_DEC) {
        return "símbolo composto";
    }
    else {
        return "símbolo simples";
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
            
            if (c == '{') {
                while (i < line.size() && line[i] != '}') {
                    i++;
                    column++;
                }
                if (i < line.size()) {
                    i++; column++;  
                }
                continue;
            }
            
            if (c == '(' && i + 1 < line.size() && line[i + 1] == '*') {
                i += 2; column += 2;
                while (i + 1 < line.size() && !(line[i] == '*' && line[i + 1] == ')')) {
                    i++;
                    column++;
                }
                if (i + 1 < line.size()) {
                    i += 2; column += 2; 
                }
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
                string two_char = string(1, c) + line[i + 1];

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

    return tokens;
}

int main() {
    vector<string> lines = readFile("input.txt");
    
    vector<Token> tokens = Lexical(lines);

    ofstream output("output.txt");

    for (const Token& token : tokens) {
        string simplifiedType = getSimplifiedTokenType(token.type);
        string info = "Lexema: \"" + token.lexema + "\" || Tipo: \"" + simplifiedType + "\"\n";
        output << info;
    }
    
    cout << "Output salvo no arquivo output.txt\n";
    output.close();
    return 0;
}