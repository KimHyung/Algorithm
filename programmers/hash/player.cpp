#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> player;
    
    for(auto c: completion){
        player[c] +=1;
    }
    
    for(auto p: participant){
        player[p] -=1;
        if(player[p]<0){
            return p;
        }
    }
}

int main(){
    string ans;
    ans = solution({"leo", "kiki", "eden"},{"eden", "kiki"});
    std::cout<<ans<<std::endl;
    return 0;
}