#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> type;
    for(auto cloth : clothes){
        type[cloth[1]] +=1;
    }
    for(auto i = type.begin(); i!=type.end();i++){
        answer *= i->second +1;
        // std::cout<<i->first<<":"<<i->second<<", answer:"<<answer<<std::endl;
    }
    std::cout<<answer<<std::endl;
    return answer-1;
}

int main(){
    solution({{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}});
    return 0;
}