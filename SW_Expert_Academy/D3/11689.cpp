#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
 
using namespace std;

//DFS 재귀 메모리 문제 x
void solution(pair<unsigned int,unsigned int> input, unsigned int up, unsigned int down, int cnt, int index ){
    int up_ans = input.first;
    int down_ans = input.second;    
    if(up <= up_ans && down <= down_ans){
        if(up_ans == up && down_ans == down){
            printf("#%d %d\n",index, cnt);
        }
        cnt++;
        cout<<index<<": "<<cnt<<","<<up<<","<<up_ans<<endl;
        solution(input, up+down, down, cnt, index);
        solution(input, up, down+up, cnt, index);
    }
    else{
        return;
    }
}

// void solution(pair<int, int> input, int up, int down, int cnt){

// }



int main()
{
    int test_case;
    int answer;
    string tmp;
    string stringBuffer;
    vector<pair<unsigned int,unsigned int>> inputs;
    
    cin >> test_case;
    cin.ignore(1, '\r');
    for(int i=0; i<test_case; i++){
        getline(cin, tmp);
        istringstream iss(tmp);
        unsigned int index[2];
        int j=0;
        while(getline(iss, stringBuffer, ' ')){
            index[j] = atoi(stringBuffer.c_str());
            j++;
        }
        inputs.push_back( make_pair(index[0],index[1]));
    }

    for(int i=0; i<inputs.size(); i++){
        // solution(inputs[i],1,1,0, i+1);
        cout<<inputs[i].first<<", "<< inputs[i].second<<endl;
    }
    return 0;
}

