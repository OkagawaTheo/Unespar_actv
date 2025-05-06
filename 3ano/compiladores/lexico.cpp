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
    SEMICOLON,  // ;
    COMMA,      // ,
    LPAREN,     // (
    RPAREN      // )
};

struct Token {
    TokenType type;
    string lexema;
    int line;
    int column;
};

unordered_map<string, TokenType> palavraReservada = {
    {"program", PROGRAM},
    {"read", READ},
    {"write", WRITE},
    {"integer", INTEGER},
    {"boolean", BOOLEAN},
    {"double", DOUBLE},
    {"function", FUNCTION},
    {"procedure", PROCEDURE},
    {"begin", BEGIN_},
    {"end", END_},
    {"and", AND},
    {"array", ARRAY},
    {"case", CASE},
    {"const", CONST},
    {"div", DIV},
    {"do", DO},
    {"downto", DOWNTO},
    {"else", ELSE_},
    {"file", FILE_},
    {"for", FOR},
    {"goto", GOTO},
    {"if", IF_},
    {"in", IN},
    {"label", LABEL},
    {"mod", MOD},
    {"nil", NIL},
    {"not", NOT_},
    {"of", OF},
    {"or", OR},
    {"packed", PACKED},
    {"record", RECORD},
    {"repeat", REPEAT},
    {"set", SET},
    {"then", THEN},
    {"to", TO},
    {"type", TYPE},
    {"until", UNTIL},
    {"with", WITH},
    {"var", VAR},
    {"while", WHILE_}
};

vector<string> readFile(const string& filename) {
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

    for (const Token& token : tokens) {
        cout << "Token: " << token.lexema << " (Linha " << token.line << ", Coluna " << token.column << ")\n"; // falta o type
    }

    return 0;
}
