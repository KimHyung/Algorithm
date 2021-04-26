#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(string departure, vector<vector<string>>& tickets,vector<bool>& visit, vector<string>& answer, vector<string>& tmp, int cnt, int& max){
    tmp.push_back(departure);
    if(max<cnt){
        max = cnt;
        answer.clear();
        answer = tmp;
    }
    for(int i=0; i<tickets.size();i++){
        if(departure == tickets[i][0] && !visit[i]){
            visit[i] = true;
            dfs(tickets[i][1], tickets, visit, answer, tmp, cnt+1, max);
            visit[i] = false;
        }
    }
    tmp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer, tmp;
    vector<bool> visit(tickets.size(), false);
    int cnt=0, max=0;
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, visit, answer, tmp, cnt, max);
    for(int i=0; i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    return answer;
}

int main(){
    vector<vector<string>> tickets ={{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
    vector<vector<string>> tickets2 = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}};
    solution(tickets);
    solution(tickets2);
}
