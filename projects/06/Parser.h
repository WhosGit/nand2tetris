#ifndef PARSER_H
#define PARSER_H
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

enum COMMAND_type{A_COMMAND, C_COMMAND, L_COMMAND};

class Parser
{
private:
    ifstream fin;
    string command;

public:
    Parser(string filename);
    ~Parser();

    bool hasMoreCommands();
    bool advance();
    COMMAND_type commandType();
    string symbol();
    string dest();
    string comp();
    string jump();


private:
    string removeComment(const std::string& line);

};
#endif