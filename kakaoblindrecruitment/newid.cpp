#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    for (char& ch : new_id) if ('A' <= ch && ch <= 'Z') ch |= 32;

    string ret;
    for (char& ch: new_id) {
        if ('a' <= ch && ch <= 'z' ||
            '0' <= ch && ch <= '9' ||
            strchr("-_.", ch)) ret += ch;
    }

    new_id = ret;
    ret.clear();
    for (char& ch: new_id) {
        if (!ret.empty() && ret.back() == '.' && ch == '.') continue;
        ret += ch;
    }

    if (ret.front() == '.') ret.erase(ret.begin());
    if (ret.back() == '.') ret.pop_back();

    if (ret.empty()) ret = "a";
    if (ret.size() >= 16) ret = ret.substr(0, 15);
    if (ret.back() == '.') ret.pop_back();
    while (ret.size() <= 2) ret += ret.back();

    return ret;
}
int main(){
    // std::cout<<"input: ...!@BaT#*..y.abcdefghijklm"<< std::endl;
    // std::cout<<solution("...!@BaT#*..y.abcdefghijklm")<<std::endl;
    
    // std::cout<<"input: z-+.^."<< std::endl;
    // std::cout<<"output: "<< solution("z-+.^.")<<std::endl;
    
    // std::cout<<"input: =.="<< std::endl;
    // std::cout<<"output: "<< solution("=.=")<<std::endl;

    std::cout<<"input: 123_.def"<< std::endl;
    std::cout<<"output: "<< solution("123_.def")<<std::endl;

    // std::cout<<"input: abcdefghijklmn.p"<< std::endl;
    // std::cout<<"output: "<< solution("abcdefghijklmn.p")<<std::endl;
    
    return 0;
}