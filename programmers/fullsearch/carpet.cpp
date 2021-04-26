#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int row, col, outlier;
    for(row=3; row<brown/2; row++){
        col = (brown-row*2)/2+2;
        if(col<row) continue;
        if((row*col-brown)==yellow){
            answer.push_back(col);
            answer.push_back(row);
            break;
        }
    }
    
    return answer;
}

int main(){
    solution(10,2);
    solution(8,1);
    solution(24,24);
    return 0;
}