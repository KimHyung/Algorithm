#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int done=0;
    int tmp=0;
    int size=progresses.size();
    while(done<size){
        for(int i=done; i<size; i++){
            progresses[i] = progresses[i] + speeds[i];
        }
        if(progresses[done]>=100){
            done++;
            tmp++;
            if(done<size){
                for(int i=done; i<size; i++){
                    if(progresses[i]>=100&&done<size){
                        done++;
                        tmp++;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        if(tmp>0){
            answer.push_back(tmp);
        }
        tmp=0;
    }

    return answer;
}

int main(){
    vector<int> answer = solution({93,30,55},{1,30,5});
    for(int i=0; i<answer.size();i++){
        printf("%d, ",answer[i]);
    }
    printf("\n");
    return 0;
}