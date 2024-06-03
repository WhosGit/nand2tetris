// Codewriter.h
#ifndef CODEWRITER_H
#define CIDEWRITER_H
#include <string>
#include <fstream>
#include <iostream>
#include <stack>
#include "Parser.h"

using namespace std;

class CodeWriter
{
private:
    ofstream fout;
    stack<string> stk;
    int symbol_index;
public:
    CodeWriter(string filename);
    ~CodeWriter();

    // my functions
    void writeComment(string command);
    void setFileName(string filename);
    void writeArithmetic(string command);
    void writePushPop(COMMAND_type Command, string segment, int index);
    void close();
};
#endif
