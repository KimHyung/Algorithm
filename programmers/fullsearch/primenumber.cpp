#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> number;
    vector<int> prime;
    for(int i=0; i< numbers.size();i++){
        number.push_back(numbers[i]);
    }
    sort(number.begin(),number.end());

    do{
        string tmp ="";
        for(int i=0; i<number.size();i++){
            tmp.push_back(number[i]);
            prime.push_back(stoi(tmp));
        }
    } while(next_permutation(number.begin(),number.end()));

    sort(prime.begin(), prime.end());
    prime.erase(unique(prime.begin(),prime.end()), prime.end());
    
    for(int i=0; i<prime.size();i++)
        if(isPrime(prime[i])) answer++;

    return answer;
}

int main(){
    vector<string> numbers ={"011"};
    for(int i=0; i<numbers.size();i++)
        solution(numbers[i]);
    return 0;
}