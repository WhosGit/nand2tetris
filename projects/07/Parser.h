// Parser.h
#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

enum COMMAND_type{C_ARITHMETIC, C_PUSH, C_POP, C_LABEL, C_GOTO, C_IF, C_FUNCTION, C_RETURN, C_CALL};

class Parser
{
private:
    ifstream fin;
    vector<string> commands;
    string command;
    const unordered_map<string, COMMAND_type> type_map = {
        {"add", C_ARITHMETIC},
        {"sub", C_ARITHMETIC},
        {"neg", C_ARITHMETIC},
        {"eq", C_ARITHMETIC},
        {"gt", C_ARITHMETIC},
        {"lt", C_ARITHMETIC},
        {"and", C_ARITHMETIC},
        {"or", C_ARITHMETIC},
        {"not", C_ARITHMETIC},
        {"pop", C_POP},
        {"push", C_PUSH},
        {"label", C_LABEL},
        {"goto", C_GOTO},
        {"if-goto", C_IF},
        {"function", C_FUNCTION},
        {"call", C_CALL},
        {"return", C_RETURN}

    };
public:
    Parser(string filename);
    ~Parser();

    // my functions
    bool hasMoreCommands();
    bool advance();
    string thisCommand();
    COMMAND_type commandType();
    string arg();
    int Arg2();

private:
    string removeComment(const std::string& line);
    
};
#endif