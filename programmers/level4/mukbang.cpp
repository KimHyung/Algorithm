#include <string>
#include <vector>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    return answer;
}

int main(){
    vector<int> food_times = {3,1,2};
    long long k = 5;
    int answer = solution(food_times,k);
    if(answer) printf("True!\n");
    else{
        printf("Wrong\nYour answer is : %d\n",answer);
    }
    return 0;
}