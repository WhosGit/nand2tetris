#include "SymbolTable.h"
#include <iostream>
SymbolTable::SymbolTable(/* args */)
{
    for(int i = 0; i < 16; i++){
        symbol_table.insert(pair<string, int>(string("R").append(to_string(i)), i));
    }

    int j = 0;
    for (string i : {"SP","LCL","ARG","THIS","THAT"})
    {
        symbol_table.insert(pair<string, int>(i, j));
        j++;
    }
    
    symbol_table.insert(pair<string, int>("SCREEN", 16384));
    symbol_table.insert(pair<string, int>("KBD", 24576));
}

SymbolTable::~SymbolTable()
{
}

void SymbolTable::addEntry(string symbol, int address)
{
    //std::cout<<"adding "<<symbol<<" as "<<address<<std::endl;
    symbol_table.insert(pair<string, int>(symbol, address));
}

bool SymbolTable::contains(string symbol)
{
    return (symbol_table.find(symbol) != symbol_table.end()); 
}

int SymbolTable::GetAddress(string symbol)
{
    return symbol_table.at(symbol);
}
