#include "Parser.h"
#include "CodeWriter.h"

int main(int argc, char *argv[]) {
    /*
    @WhosGit
    输入：prompt> Vmtranslator source 
    source是Xxx.vm文件的文件名，或是包含一至多个文件的路径名称。
    编译结果是生成一个单一名为Xxx.asm的汇编语言文件。
    */ 

   //cout<<string(argv[1]).substr(0,string(argv[1]).find('.')).append("1.hack");
   CodeWriter cw(string(argv[1]).substr(0,string(argv[1]).find('.')).append(".asm"));
    Parser par(argv[1]);
    while (par.hasMoreCommands()&&par.advance())
    {
        //cout<<1<<endl;
        cw.writeComment(par.thisCommand());
        switch (par.commandType())
        {
        case C_ARITHMETIC:
            //cout<<2<<endl;
            cw.writeArithmetic(par.arg());
            break;
        
        default:
            cw.writePushPop(par.commandType(), par.arg(), par.Arg2());
            break;
        }
    }
    
   

}