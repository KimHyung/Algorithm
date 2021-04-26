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
    vector<vector<string>> dev;
    vector<vector<string>> dev_tmp;
    vector<int> erasePtr;
    vector<string> tmp;
    
    for(int i=0 ; i<info.size(); i++){
        result = split(info[i],' ');
        for(int i=0; i<result.size();i++){
            tmp.push_back(result[i]);
        }
        dev.push_back(tmp);
        tmp.clear();
        result.clear();
    }

    for(int i=0; i<query.size(); i++){
        result = split(query[i],' ');
        for(int k=0; k<result.size();k++){
            dev_tmp = dev;
            if(result[k].compare("-")==0) continue;

            if(k != 4){
                for(int j=0; j<dev_tmp.size();j++){
                    if(dev_tmp[j][k].compare(result[k])!=0){
                        erasePtr.push_back(j);
                    }
                }
            }
            else{
                for(int j=0;j<dev_tmp.size();j++){
                    if(stoi(dev_tmp[j][k])<stoi(result[k])){
                        erasePtr.push_back(j);
                        // dev_tmp.erase(dev_tmp.begin()+k);
                    }
                }
            }
        }
        cout<<"before"<<endl;
        for(int l=0;l<erasePtr.size();l++){
            cout<<erasePtr[l]<<endl;
            dev_tmp.erase(dev_tmp.begin()+erasePtr[l]);
        }
        cout<<"after"<<endl;
        answer.push_back(dev_tmp.size());
        erasePtr.clear();
        dev_tmp.clear();
        result.clear();
        // for(int j=0; j<dev.size(); j++){
        //     if(dev[j].language.compare(result[0])!=0){
        //         if(result[0].compare("-")!=0){
        //             continue;
        //         }
        //     }
        //     if(dev[j].position.compare(result[1])!=0){
        //         if(result[1].compare("-")!=0){
        //             continue;
        //         }
        //     }
        //     if(dev[j].rank.compare(result[2])!=0){
        //         if(result[2].compare("-")!=0){
        //             continue;
        //         }
        //     }
        //     if(dev[j].soulfood.compare(result[3])!=0){
        //         if(result[3].compare("-")!=0){
        //             continue;
        //         }
        //     }
        //     if(result[4].compare("-")!=0 && stoi(dev[j].score)<stoi(result[4]) ){
        //         continue;
        //     }
        //     cnt++;
        // }
        // answer.push_back(cnt);
    }

    return answer;
}

int main(){
    vector<string> info;
    vector<string> query;
    info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
    solution(info, query);
    return 0;
}