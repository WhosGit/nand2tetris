// parser.cpp
#include "Parser.h"

// 打开文件，准备进行语法解析
Parser::Parser(string filename)
{
}

Parser::~Parser()
{
}

// 返回是否还有更多命令
bool Parser::hasMoreCommands()
{
    return false;
}

// 读取下一条命令，仅在hasMoreCommands为真的情况下调用
void Parser::advance()
{
}

// 返回当前VM命令类型，对于所有算数命令，总返回C_ARITHMETIC
COMMAND_type Parser::commandType()
{
    return COMMAND_type();
}

// 返回当前命令的第一个参数，如果命令为C_ARITHMETIC类型，返回命令本身
string Parser::arg()
{
    return string();
}

// 返回当前命令的第二个参数，仅在C_PUSH,C_POP,C_FUNCTION,C_CALL命令时调用
int Parser::Arg2()
{
    return 0;
}
