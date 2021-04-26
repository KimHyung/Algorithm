#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

struct developer{
    string language;
    string position;
    string rank;
    string soulfood;
    string score;
    bool   check = true;
};

vector<string> split(string input, char del){
    vector<string> ans;
    stringstream ss(input);
    string buffer="";
    string x = "and";
    while(getline(ss, buffer, del)){
        if(x.compare(buffer)==0){
            continue;
        }
        ans.push_back(buffer);
    }
    return ans;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<string> result;
    vector<developer> dev;
    struct developer tmp;
    
    for(int i=0 ; i<info.size(); i++){
        result = split(info[i],' ');
        tmp.language = result[0];
        tmp.position = result[1];
        tmp.rank = result[2];
        tmp.soulfood = result[3];
        tmp.score = result[4];
        dev.push_back(tmp);
        result.clear();
    }

    for(int i=0; i<query.size(); i++){
        int cnt=0;
        result = split(query[i],' ');
        for(int j=0; j<dev.size(); j++){
            if(dev[j].language.compare(result[0])!=0){
                if(result[0].compare("-")!=0){
                    continue;
                }
            }
            if(dev[j].position.compare(result[1])!=0){
                if(result[1].compare("-")!=0){
                    continue;
                }
            }
            if(dev[j].rank.compare(result[2])!=0){
                if(result[2].compare("-")!=0){
                    continue;
                }
            }
            if(dev[j].soulfood.compare(result[3])!=0){
                if(result[3].compare("-")!=0){
                    continue;
                }
            }
            if(result[4].compare("-")!=0 && stoi(dev[j].score)<stoi(result[4]) ){
                continue;
            }
            cnt++;
        }
        answer.push_back(cnt);
        result.clear();
    }

    return answer;
}