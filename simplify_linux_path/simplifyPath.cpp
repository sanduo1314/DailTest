#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string path(string path)
{
    string result ,tmp ;
    stringstream s(path);
    vector <string> vstr;
    while (getline(s , tmp,'/'))
    {
        if (tmp == "" || tmp == ".")
            continue;
        if (tmp == ".." && !vstr.empty())
            vstr.pop_back();
        else if (tmp != "..")
            vstr.push_back(tmp);
    }
    
    for (string s : vstr)
        result += "/"+s;
    return result.empty() ? "/":result;
}

int main()
{
    string str;
    std::cin>>str;
    std::cout<<path(str)<<std::endl;
    return 0;
}

