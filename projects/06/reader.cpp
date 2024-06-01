// 这是一个文本阅读的测试文件，将注释和空格从汇编语句中删除
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

// 去除行末尾的注释
std::string removeComment(const std::string& line) {
    size_t pos = line.find("//");
    if (pos != std::string::npos) {
        return line.substr(0, pos);
    }
    return line;
}


int main(int argc, char* argv[]) {
    string filename = argv[1];

    ifstream fin(filename);
    string s;
    while (fin)
    {
        do
        {
            getline(fin, s);
            //cout<<s<<endl;
            s.erase(remove(s.begin(), s.end(), ' '), s.end());
            //remove(s.begin(), s.end(), ' ');
            //cout<<s<<endl;
            s = removeComment(s);
            //cout<<s<<endl;
            
        } while (fin && s.empty());
        if (!s.empty())
        {
            cout<<s<<endl;
        }
    }
    
    


    fin.close();
}