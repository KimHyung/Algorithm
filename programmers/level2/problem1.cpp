#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> split(string input, char det){
    vector<string> words;
    stringstream ss(input);
    string tmp;
    while(getline(ss, tmp, det)){
        if(tmp.size()>1){
            words.push_back(tmp);
        }
    }
    return words;
}

int main(){
    string s = "for the last week";
    string answer = "";
    vector<string> words = split(s, ' ');
    for(int i=0; i<words.size(); i++){
        for(int j=0; j<words[i].size(); j++){
            if(j==0){
                if(words[i][j]>=97){
                    char c = int(words[i][j])-32;
                    words[i][j] = c;
                }
            }
            else{
                if(words[i][j]<97){
                    char c = int(words[i][j])+32;
                    words[i][j] = c;
                }
            }
        }
        answer.append(words[i]);
        if(i!=words.size()-1){
            answer.append(" ");
        }
    }

    std::cout<<answer<<endl;
    return 0;
}

