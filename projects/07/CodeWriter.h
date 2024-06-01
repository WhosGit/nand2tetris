// Codewriter.h
#ifndef CODEWRITER_H
#define CIDEWRITER_H
#include <string>
#include <fstream>
#include <iostream>
#include "Parser.h"

using namespace std;

class CodeWriter
{
private:

public:
    CodeWriter(string filename);
    ~CodeWriter();

    // my functions
    void setFileName(string filename);
    void writeArithmetic(string command);
    void writePushPop(COMMAND_type Command, string segment, int index);
    void close();
};
#endif
