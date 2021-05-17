#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>a, pair<int, int>b){
	if (a.second == b.second)   return a.first < b.first;
	else    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genres_play;
    map<int, string> value_based;
    map<string, vector<pair<int, int>>> genres_id;
    
    for(int i=0; i< genres.size(); i++){
        genres_play[genres[i]]+=plays[i];
        genres_id[genres[i]].push_back(make_pair(i, plays[i]));
    }
    for(auto iter = genres_play.begin() ;iter!=genres_play.end(); iter++){
        value_based[iter->second] = iter->first;
    }
    for(auto iter = genres_id.begin() ;iter!=genres_id.end(); iter++){
        vector<pair<int,int>> tmp;
        tmp = iter->second;
        sort(tmp.begin(),tmp.end(), compare);
        iter->second = tmp;
    }
    for(auto iter = value_based.begin(); iter != value_based.end(); iter++){
        int size;
        if(genres_id[iter->second].size()>2){
            size  = genres_id[iter->second].size()-2;
        }
        else{
            size=0;
        }
        for(int i=size;i<genres_id[iter->second].size();i++){
            answer.push_back(genres_id[iter->second][i].first);
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;
}

int main(){
    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 600, 150, 800, 2500};
    vector<int> answer;

    answer = solution(genres, plays);
    // for(int i=0; i< answer.size(); i++){
    //     cout<<answer[i]<<" ";
    // }
    return 0;
}