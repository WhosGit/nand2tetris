
#ifndef CODE_H
#define CODE_H

#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

class Code
{
private:
    const unordered_map<string, string> compMap = {
        {"0", "101010"},
        {"1", "111111"},
        {"-1", "111010"},
        {"D", "001100"},
        {"A", "110000"},
        {"!D", "001101"},
        {"!A", "110001"},
        {"-D", "001111"},
        {"-A", "110011"},
        {"D+1", "011111"},
        {"A+1", "110111"},
        {"D-1", "001110"},
        {"A-1", "110010"},
        {"D+A", "000010"},
        {"A+D", "000010"},
        {"D-A", "010011"},
        {"A-D", "000111"},
        {"D&A", "000000"},
        {"D|A", "010101"},
        {"A&D", "000000"},
        {"A|D", "010101"}
    };

    const unordered_map<string, string> compMap2 = {
        {"M", "110000"},
        {"!M", "110001"},
        {"-M", "110011"},
        {"M+1", "110111"},
        {"M-1", "110010"},
        {"D+M", "000010"},
        {"M+D", "000010"},
        {"D-M", "010011"},
        {"M-D", "000111"},
        {"D&M", "000000"},
        {"D|M", "010101"},
        {"M&D", "000000"},
        {"M|D", "010101"}
    };

    const unordered_map<string, string> jmpMap = {
        {"", "000"},
        {"JGT", "001"},
        {"JEQ", "010"},
        {"JGE", "011"},
        {"JLT", "100"},
        {"JNE", "101"},
        {"JLE", "110"},
        {"JMP", "111"}
    };

public:
    Code(/* args */);
    ~Code();

    string dest(string dest_);
    string comp(string comp_);
    string jump(string jump_);

};
#endif