#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <string>
#include <cctype.h>
using namespace std;


enum TokenType{
    PROGRAM, READ, WRITE, INTEGER, BOOLEAN, DOUBLE,
    FUNCTION, PROCEDURE, BEGIN_, END_,
    AND, ARRAY, CASE, CONST, DIV, DO, DOWNTO, ELSE_, FILE_, FOR,
    GOTO, IF_, IN, LABEL, MOD, NIL, NOT_, OF, OR, PACKED,
    RECORD, REPEAT, SET, THEN, TO, TYPE, UNTIL, WITH, VAR, WHILE_,
    IDENTIFIER, NUMBER, SYMBOL, END_OF_FILE,

     // Operadores básicos
     OP_ASSIGN,  // :=
     OP_EQ,      // =
     OP_PLUS,    // +
     OP_MINUS,   // -
     
     // Delimitadores
     SEMICOLON,  // ;
     COMMA,      // ,
     LPAREN,     // (
     RPAREN,     // )
     
};

struct Token{
    TokenType type;
    string lexema;
    int line;
    int column;
};

unordered_map<string,TokenType> palavraReservada = {
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


vector<string> readFile(const string& filename){
    ifstream file(filename);
    
    if (!file.is_open()){
        throw runtime_error("Erro ao abrir o arquivo "+ filename);
    }
    string line;
    vector<string> vector_lines; //

    while(getline(file,line)){ // le linha por linha
        vector_lines.push_back(line); // add no vetor as linhas do txt
    }

    file.close();
    return vector_lines;
}


vector<string> Lexical(const vector<string>& lines){
    vector<Token> tokens;
   
   int line_number = 1;

   for(const string& line : lines){
    int i = 0;
    int column = 1;

    for(char c : line){
        if (isspace(c)){
            column++; //column registra posicao do c na linha
            i++;
            continue;
        }

        if (isalpha(c)){
            string lexema(1,c);
            int start_col = column;
            i++;
            column++;
            
        }






    }

   }

}

int main(){
    vector<string> lines = readFile("input.txt");
    int numero_linha = 1;
    for(const string& linha : lines){
        cout << "Linha: " << numero_linha++ << ": " << linha <<endl;
    }
}