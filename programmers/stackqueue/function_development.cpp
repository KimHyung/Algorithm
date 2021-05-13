#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int release=0;
    reverse(progresses.begin(), progresses.end());
    reverse(speeds.begin(), speeds.end());

    while(!progresses.empty()){
        for(int i=progresses.size()-1; i>=0; i--){
            if(progresses[i]>=100 && i==progresses.size()-1){
                release++;
                progresses.pop_back();
                continue;
            }
            progresses[i] = progresses[i]+speeds[i]; 
        }
        if(release!=0){
            answer.push_back(release);
            release=0;
        }
    }

    return answer;
}

int main(){
    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};

    solution(progresses, speeds);


    return 0;
}