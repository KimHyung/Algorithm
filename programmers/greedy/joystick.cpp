#include <string>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int solution(string name) {
    int answer = 0;
    int cursor = 0;
    int idx=0;
    int min;
    string inputs(name.size(),'A');
    while(true){
        if(inputs==name) break;
        min=20;
        for(int move=0; move<name.size(); move++){
            if(name[move]==inputs[move]) continue;

            int tl = abs(cursor-move);
            int tr = abs(int(name.size())+cursor-move);
            int tmp = tl<tr?tl:tr;

            if(tmp < min){
                idx = move;
                min = tmp;
            }
        }
        cursor = idx;
        answer += min;
        int l = abs(name[cursor]-inputs[cursor]);
        int r = abs('Z'-name[cursor]+1);
        answer+= l<r?l:r;
        inputs[cursor] = name[cursor];
    }
    return answer;
}

int main(){
    solution("JAZ");
    return 0;
}