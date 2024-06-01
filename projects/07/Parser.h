// Parser.h
#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

enum COMMAND_type{C_ARITHMETIC, C_PUSH, C_POP, C_LABEL, C_GOTO, C_IF, C_FUNCTION, C_RETURN, C_CALL};

class Parser
{
private:
    ifstream fin;
public:
    Parser(string filename);
    ~Parser();

    // my functions
    bool hasMoreCommands();
    void advance();
    COMMAND_type commandType();
    string arg();
    int Arg2();
    
};
#endif