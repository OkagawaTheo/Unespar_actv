#include <iostream>
#include <unordered_map>
using namespace std;


enum TokenType{
    PROGRAM, READ, WRITE, INTEGER, BOOLEAN, DOUBLE,
    FUNCTION, PROCEDURE, BEGIN_, END_,
    AND, ARRAY, CASE, CONST, DIV, DO, DOWNTO, ELSE_, FILE_, FOR,
    GOTO, IF_, IN, LABEL, MOD, NIL, NOT_, OF, OR, PACKED,
    RECORD, REPEAT, SET, THEN, TO, TYPE, UNTIL, WITH, VAR, WHILE_,
    IDENTIFIER, NUMBER, SYMBOL, END_OF_FILE
};

struct Token{
    TokenType type;
    string lexema;
}

unordered_map<string,TokenType> PalavraReservada = {
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


int main(){
  
}