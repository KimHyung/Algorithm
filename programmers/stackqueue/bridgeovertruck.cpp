#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int pressure = 0; 
    queue<int> waitlines;
    queue<int> inlines;
    int truck;
    for(auto t : truck_weights) waitlines.push(t);
    for(int i=0; i<bridge_length; i++) inlines.push(0);
    
    while(!waitlines.empty()){
        if(inlines.size()==bridge_length){
            pressure-=inlines.front();
            inlines.pop();
        }
        truck = waitlines.front();
        if(pressure+truck<= weight&&inlines.size()<=bridge_length){
            pressure+=truck;
            inlines.push(truck);
            waitlines.pop();
        }
        else{
            inlines.push(0);
        }
        answer++;
    }
    
    while(!inlines.empty()){
        inlines.pop();
        answer++;
    }
    return answer;
}

int main(){
    vector<int> truck_weights={10,10,10,10,10,10,10,10,10,10}; 
    int weight = 100;
    int bridge_length = 100;

    solution(bridge_length, weight, truck_weights);

    return 0;
}