// CodeWriter.cpp
#include "CodeWriter.h"

// 打开输出文件，准备进行写入
CodeWriter::CodeWriter(string filename)
{
}

CodeWriter::~CodeWriter()
{
}

// 通知代码写入程序，新的VM文件翻译过程已经开始
void CodeWriter::setFileName(string filename)
{
}

// 将给定的算术操作所对应的汇编代码写至输出
void CodeWriter::writeArithmetic(string command)
{
}

// 将给定的command(C_PUSH,C_POP)所对应的汇编代码写入输出
void CodeWriter::writePushPop(COMMAND_type Command, string segment, int index)
{
}

// 关闭文件流
void CodeWriter::close()
{
}
