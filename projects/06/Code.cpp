#include "Code.h"
#include <iostream>
Code::Code(/* args */)
{
}

Code::~Code()
{
}

string Code::dest(string dest_)
{
    //cout<<"finding dest: "<<dest_<<endl;
    string bi_dest;
    char a[] = {'A', 'D', 'M'};
    for (int i = 0; i < 3; i++)
    {
        if (dest_.find(a[i]) != string::npos)
        {
            bi_dest.append("1");
        }
        else
        {
            bi_dest.append("0");
        }
    }

    return bi_dest;

}

string Code::comp(string comp_)
{
    if (comp_.find("M")!=string::npos)
    {
        string result{"1"};
        return result.append(compMap2.at(comp_));
    }
    
    string result{"0"};
    return result.append(compMap.at(comp_));
    
}

string Code::jump(string jump_)
{
    return jmpMap.at(jump_);
}
