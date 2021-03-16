#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k){
    string answer = "";
    
    for(int i=0, fork=-1; i<number.size()-k; i++){
        char max=0;
        for(int j=fork+1;j<=k+i;j++){
            if(max<number[j]){
                fork = j;
                max = number[j];
            }
        }
        cout<< max <<endl;
        answer.push_back(max);
    }
    cout<<endl;
    cout<<answer<<endl;
    return answer;
}

int main(){
    string answer;
    answer = solution("1924", 2);
    printf("ans %s",answer);
}