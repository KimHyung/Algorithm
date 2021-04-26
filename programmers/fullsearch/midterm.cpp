#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

vector<int> stu1 = {1,2,3,4,5};
vector<int> stu2 = {2,1,2,3,2,4,2,5};
vector<int> stu3 = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers){
    vector<int> answer;
    int cnt[3] ={0,0,0}, max;

    for(int i=0; i<answers.size();i++){
        if(stu1[i%stu1.size()] == answers[i])   cnt[0]++;
        if(stu2[i%stu2.size()] == answers[i])   cnt[1]++;
        if(stu3[i%stu3.size()] == answers[i])   cnt[2]++;
    }
    
    answer.push_back(1);
    max = cnt[0];
    for(int i=1; i<3; i++){
        if(max < cnt[i]){
            answer.clear();
            answer.push_back(i+1);
            max = cnt[i];
        }
        else if(max == cnt[i]){
            answer.push_back(i+1);
        }
    }
    return answer;
}

int main(){
    vector<int> ans;
    ans = solution({1,2,3,4,5});
    return 0;
}