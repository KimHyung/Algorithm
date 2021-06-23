#include <vector>
#include <string>
#include <iostream>
using namespace std;

int solution(vector<string> arr)
{
    int answer = -1;
    vector<int> num;
    int plus = 0;
    int minus =0;

    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size();j++){
            if(arr[i][j]=='+'){
                
            }
        }
    }

    return answer;
}

int main(){
    vector<string> prb1 = {"1", "-", "3", "+", "5", "-", "8"};
    int ans1 = 1;
    vector<string> prb2 = {"5", "-", "3", "+", "1", "+", "2", "-", "4"};
    int ans2 = 3;
    
    if(ans1 == solution(prb1)) printf("problem1 solved\n");
    else    printf("problem1 wrong\n");

    if(ans1 == solution(prb2)) printf("problem2 solved\n");
    else    printf("problem2 wrong\n");

    return 0;
}