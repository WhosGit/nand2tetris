// CodeWriter.cpp
#include "CodeWriter.h"

// 打开输出文件，准备进行写入
CodeWriter::CodeWriter(string filename): fout(filename), symbol_index(0)
{
    if (!fout) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        exit(1);
    }
}

CodeWriter::~CodeWriter()
{
}

void CodeWriter::writeComment(string command)
{
    fout<<endl<<"//"<<command<<endl;
}

// 通知代码写入程序，新的VM文件翻译过程已经开始
void CodeWriter::setFileName(string filename)
{
}

// 将给定的算术操作所对应的汇编代码写至输出
void CodeWriter::writeArithmetic(string command)
{
    if (command == "add")
    {
        fout
        <<"@SP\nAM=M-1\nD=M\nA=A-1\nM=D+M"<<endl;
    }

    if (command == "sub")
    {
        fout
        <<"@SP\nAM=M-1\nD=M\nA=A-1\nM=M-D"<<endl;
    }

    if (command == "neg")
    {
        fout
        <<"@SP\nA=M-1\nM=-M"<<endl;
    }

    if (command == "not")
    {
        fout
        <<"@SP\nA=M-1\nM=!M"<<endl;
    }

    if (command == "and")
    {
        fout
        <<"@SP\nAM=M-1\nD=M\nA=A-1\nM=D&M"<<endl;
    }

    if (command == "or")
    {
        fout
        <<"@SP\nAM=M-1\nD=M\nA=A-1\nM=D|M"<<endl;
    }
    
    

    if (command == "eq")
    {
        fout
        <<"@SP\nAM=M-1\nD=M\nA=A-1\nD=M-D\nM=0\n@"<<command<<symbol_index<<endl
        <<"D;JNE\n"<<"@SP\nA=M-1\n"<<"M=-1\n"
        <<"("<<command<<symbol_index<<")"<<endl;
        symbol_index++;
        
    }
    
    if (command == "gt")
    {
        fout
        <<"@SP\nAM=M-1\nD=M\nA=A-1\nD=M-D\nM=0\n@"<<command<<symbol_index<<endl
        <<"D;JLE\n"<<"@SP\nA=M-1\n"<<"M=-1\n"
        <<"("<<command<<symbol_index<<")"<<endl;
        symbol_index++;
        
    }
    
    if (command == "lt")
    {
        fout
        <<"@SP\nAM=M-1\nD=M\nA=A-1\nD=M-D\nM=0\n@"<<command<<symbol_index<<endl
        <<"D;JGE\n"<<"@SP\nA=M-1\n"<<"M=-1\n"
        <<"("<<command<<symbol_index<<")"<<endl;
        symbol_index++;
        
    }
    
}

// 将给定的command(C_PUSH,C_POP)所对应的汇编代码写入输出
void CodeWriter::writePushPop(COMMAND_type Command, string segment, int index)
{
    switch (Command)
    {
    case C_PUSH:
        if (segment == "argument")
        {
            fout<<"@ARG\nD=M\n@"<<index<<endl<<"A=D+A\n";
            fout<<"D=M\n@SP\nA=M\nM=D\n@SP\nM=M+1"<<endl;
        }

        if (segment == "local")
        {
            fout<<"@LCL\nD=M\n@"<<index<<endl<<"A=D+A\n";
            fout<<"D=M\n@SP\nA=M\nM=D\n@SP\nM=M+1"<<endl;
        }

        if (segment == "static")
        {
            fout<<"@"<<16+index<<endl;
            fout<<"D=M\n@SP\nA=M\nM=D\n@SP\nM=M+1"<<endl;
        }

        if (segment == "constant")
        {
            fout<<"@"<<index<<endl;
            fout<<"D=A\n@SP\nA=M\nM=D\n@SP\nM=M+1"<<endl;
        }

        if (segment == "this")
        {
            fout<<"@THIS\nD=M\n@"<<index<<endl<<"A=D+A\n";
            fout<<"D=M\n@SP\nA=M\nM=D\n@SP\nM=M+1"<<endl;
        }
        
        if (segment == "that")
        {
            fout<<"@THAT\nD=M\n@"<<index<<endl<<"A=D+A\n";
            fout<<"D=M\n@SP\nA=M\nM=D\n@SP\nM=M+1"<<endl;
        }

        if (segment == "pointer")
        {
            fout<<"@THIS\nD=A\n@"<<index<<endl<<"A=D+A\n";
            fout<<"D=M\n@SP\nA=M\nM=D\n@SP\nM=M+1"<<endl;
        }

        if (segment == "temp")
        {
            fout<<"@"<<5+index<<endl;
            fout<<"D=M\n@SP\nA=M\nM=D\n@SP\nM=M+1"<<endl;
        }
        
        break;

    case C_POP:
        if (segment == "argument")
        {
            fout<<"@"<<index<<endl<<"D=A\n@ARG\nD=D+M\n@R15\nM=D\n@SP\nAM=M-1\nD=M\n@R15\nA=M\nM=D"<<endl;
        }

        if (segment == "local")
        {
            fout<<"@"<<index<<endl<<"D=A\n@LCL\nD=D+M\n@R15\nM=D\n@SP\nAM=M-1\nD=M\n@R15\nA=M\nM=D"<<endl;
        }

        if (segment == "static")
        {
            fout<<"@SP\nAM=M-1\nD=M\n@"<<16+index<<endl<<"M=D\n";
        }

        if (segment == "this")
        {
            fout<<"@"<<index<<endl<<"D=A\n@THIS\nD=D+M\n@R15\nM=D\n@SP\nAM=M-1\nD=M\n@R15\nA=M\nM=D"<<endl;
        }
        
        if (segment == "that")
        {
            fout<<"@"<<index<<endl<<"D=A\n@THAT\nD=D+M\n@R15\nM=D\n@SP\nAM=M-1\nD=M\n@R15\nA=M\nM=D"<<endl;
        }

        if (segment == "pointer")
        {
            fout<<"@"<<index<<endl<<"D=A\n@THIS\nD=D+A\n@R15\nM=D\n@SP\nAM=M-1\nD=M\n@R15\nA=M\nM=D"<<endl;
        }

        if (segment == "temp")
        {
            fout<<"@SP\nAM=M-1\nD=M\n@"<<5+index<<endl<<"M=D\n";
        }
        
        break;
    
    default:
        break;
    }
}

// 关闭文件流
void CodeWriter::close()
{
    fout.close();
}
