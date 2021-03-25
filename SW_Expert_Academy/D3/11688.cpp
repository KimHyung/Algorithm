#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

pair<int,int> solution(string index){
    int up=1;
    int down=1;
    pair<int,int> ans;

    for(int i=0; i<index.size(); i++){
        if(index[i]=='L'){
            down += up;
        }
        else if(index[i]='R'){
            up += down;
        }
        else{
            cout<<"wrong input, "<<index[i]<<endl;
        }
    }
    ans= make_pair(up ,down);

    return ans;
}

int main(){
    int test_case;
    vector<string> inputs;
    pair<int,int> answer;
    string tmp;

    cin >> test_case;

    for(int i=0; i<test_case; i++){
        cin >> tmp;
        inputs.push_back(tmp);
    }

    for(int i=0; i<inputs.size(); i++){
        answer = solution(inputs[i]);

        cout <<"#"<<i+1<<" "<<answer.first<<" "<<answer.second<< endl;
    }


    return 0;
}