#include "Code.h"
#include "Parser.h"
#include "SymbolTable.h"
#include <fstream>
#include <bitset>
#include <iostream>


int main(int argc, char* argv[]) {
    string filename = argv[1];

    // create 3 modules

    Parser parser(filename);
    Code code;
    SymbolTable table;

    // 读取所有L指令的symbol

    int pc = 0; // program counter
    while (parser.hasMoreCommands()&&parser.advance())
    {
        if (parser.commandType() == L_COMMAND)
        {
            table.addEntry(parser.symbol(), pc);
        }
        else
        {
            pc++;
        }
    }
    
    // return 0; // 先跳过转换部分
    // 第二遍读取,同时写入

    ofstream fout(filename.substr(0,filename.find('.')).append("1.hack"));
    Parser parser1(filename);
    int address_counter = 16;
    while (parser1.hasMoreCommands()&&parser1.advance())
    {
        //std::cout<<"1\n";
        if (parser1.commandType() == A_COMMAND)
        {
            //std::cout<<"2\n";
            string symbol = parser1.symbol();
            if (symbol[0] - '0' < 10 && symbol[0] - '0' >= 0)
            {
                //std::cout<<"true\n";
                bitset<16> b(stoi(symbol));
                fout<<b.to_string()<<endl;
            }
            else 
            {
                if (!table.contains(symbol))
                {
                    table.addEntry(symbol, address_counter);
                    address_counter++;
                }
                bitset<16> b(table.GetAddress(symbol));
                fout<<b.to_string()<<endl;
                
            }
            
            
        }
        else if (parser1.commandType() == C_COMMAND)
        {
            //std::cout<<"3\n";
            
            fout<<111<<code.comp(parser1.comp())<<code.dest(parser1.dest())<<code.jump(parser1.jump())<<endl;
        }
        
    }

    // 关闭文件流
    fout.close();
    

}