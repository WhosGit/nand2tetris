#include "Parser.h"
#include <iostream>
// 打开文件流
Parser::Parser(string filename)
{
    fin.open(filename);
}

// 关闭文件流
Parser::~Parser()
{
    fin.close();
}

// 输入当前是否还有更多指令
bool Parser::hasMoreCommands()
{
    if (fin)
    {
        return true;
    }
    return false;
}

// 读取下一个命令
bool Parser::advance()
{
    do
    {
        getline(fin, command);
        command.erase(remove(command.begin(),  command.end(), ' '), command.end());
        command = removeComment(command);
    } while (command.empty()&&hasMoreCommands());

    //cout<<command<<endl;
    return !command.empty();
}

// 返回当前命令类型
COMMAND_type Parser::commandType()
{
    if (command[0] == '@')
    {
        return A_COMMAND;
    }
    else if (command[0] == '(')
    {
        return L_COMMAND;
    }
     
    //cout<<command; 
    return C_COMMAND;
}

// 返回当前的命令的符号或十进制值，仅在A或L命令时调用
string Parser::symbol()
{

    if (commandType() == A_COMMAND)
    {
        return command.substr(1);
    }
    else
    {
        return command.substr(1,command.length()-2);
    }
    
}

// 返回C指令中的dest助记符，仅在C命令时调用
string Parser::dest()
{
    size_t found = command.find("=");
    if (found == string::npos)
    {
        return "";
    }
    
    return command.substr(0, found);
}

// 返回当前指令的comp助记符，仅在C命令时调用
string Parser::comp()
{
    size_t found1 = command.find("=");
    if (found1 == string::npos)
    {
        found1 = -1;
    }

    size_t found2 = command.find(";");
    if (found2 == string::npos)
    {
        found2 = command.length();
    }
    
    //cout<<command.substr(found1+1, found2-found1-1)<<endl;
    return command.substr(found1+1, found2-found1-1);
}

// 返回当前C指令的jump助记符
string Parser::jump()
{
    size_t found2 = command.find(";");
    if (found2 == string::npos)
    {
        return "";
    }
    return command.substr(found2+1);
}

// 去除行末尾的注释
std::string Parser::removeComment(const std::string& line) {
    size_t pos = line.find("//");
    if (pos != std::string::npos) {
        return line.substr(0, pos);
    }
    return line;
}
