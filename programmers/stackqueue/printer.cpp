#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int max=0, cursor=0;
    queue<pair<int,bool>> q;
    priority_queue<int> q_max;

    for(int i=0; i< priorities.size(); i++){
        if(i==location){
            q.push(make_pair(priorities[i],true));
        }
        else{
            q.push(make_pair(priorities[i],false));
        }
        q_max.push(priorities[i]);
    }

    while(!q.empty()){
        int value = q.front().first;
        int status = q.front().second;
        q.pop();
        if(value!= q_max.top()){
                q.push(make_pair(value, status));
        }
        else{
            q_max.pop();
            answer++;
            if(status) break;
        }
    }
    return answer;    
}

int main(){
    vector<int> priorities = {2, 1, 3, 2};
    int location = 2;
    solution(priorities, location);
    return 0;
}