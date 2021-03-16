#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> db;
    for(int i=0; i<cities.size();i++){
        string tmp;
        tmp = cities[i];
        int dbSize = db.size();
        if(tmp=="\0") break;
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);

        auto it = find(db.begin(), db.end(), tmp);

        if(it != db.end()){
            answer +=1;
            db.erase(it);
        }
        else{
            answer +=5;
            if(cacheSize==dbSize && cacheSize!=0){
                db.erase(db.end());
            }
        }

        if(cacheSize!=0){
            db.insert(db.begin(), tmp);
        }
    }
    
    return answer;
}

int main(){
    int cacheSize = 3;
    vector<string> cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};

    int answer = solution(cacheSize, cities);

    printf("Execution time : %d(s)", answer);

    return 0;
}