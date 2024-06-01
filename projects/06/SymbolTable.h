#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <string>
#include <unordered_map>
using namespace std;

class SymbolTable
{
private:
    unordered_map<string, int> symbol_table;
public:
    SymbolTable(/* args */);
    ~SymbolTable();

    void addEntry(string symbol, int address);
    bool contains(string symbol);
    int GetAddress(string symbol);
};
#endif