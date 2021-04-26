#include <string>
#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<int>& numbers, int target, int sum, int cnt, int& answer){
    if (cnt == numbers.size()){
        if (sum == target) answer++;
        return;
    }
        dfs(numbers, target, sum + numbers[cnt], cnt + 1, answer);
        dfs(numbers, target, sum - numbers[cnt], cnt + 1, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0, 0, answer);
    return answer;
}

int main(){
    int ans;
    ans = solution({1,1,1,1,1}, 3);
    cout<<ans<<endl;
    return 0;
}