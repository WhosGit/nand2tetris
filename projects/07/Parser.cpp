// parser.cpp
#include "Parser.h"

// @WhosGit
// 打开文件，准备进行语法解析
Parser::Parser(string filename): fin(filename)
{
    if (!fin) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        exit(1);
    }
}

Parser::~Parser()
{
    fin.close();
}

// 返回是否还有更多命令
bool Parser::hasMoreCommands()
{
    if (fin)
    {
        return true;
    }
    
    return false;
}

// 读取下一条命令，仅在hasMoreCommands为真的情况下调用, 返回是否成功读取
bool Parser::advance()
{
    do
    {
        getline(fin, command);
        //command.erase(remove(command.begin(),  command.end(), ' '), command.end());
        command = removeComment(command);

        commands.clear();
        stringstream ss(command);
        string token;
        char delimiter = ' ';
        while (getline(ss, token, delimiter))
        {
            commands.push_back(token);
        }
        
    } while (command.empty()&&hasMoreCommands());

    //cout<<command<<endl;
    return !command.empty();
}

// 返回当前VM命令类型，对于所有算数命令，总返回C_ARITHMETIC
COMMAND_type Parser::commandType()
{
    return type_map.at(commands[0]);
}

string Parser::thisCommand()
{
    return string(command);
}

// 返回当前命令的第一个参数，如果命令为C_ARITHMETIC类型，返回命令本身
string Parser::arg()
{
    if (commandType() == C_ARITHMETIC)
    {
        return commands[0];
    }
    
    return string(commands[1]);
}

// 返回当前命令的第二个参数，仅在C_PUSH,C_POP,C_FUNCTION,C_CALL命令时调用
int Parser::Arg2()
{
    return stoi(commands[2]);
}

// 去除行末尾的注释
std::string Parser::removeComment(const std::string& line) {
    size_t pos = line.find("//");
    if (pos != std::string::npos) {
        return line.substr(0, pos);
    }
    return line;
}
