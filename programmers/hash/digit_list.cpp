#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for(int i=0; i<phone_book.size()-1;i++){
        bool check = true;
        for(int j=0;j<phone_book[i].size();j++){
            if(phone_book[i][j]!=phone_book[i+1][j]){
                check = false;
                break;
            }
        }
        if(check){
            return false;
        }
    }
    return true;
}

int main(){
    vector<vector<string>> test;
    test = {{"12", "88","123","567","1235"},{"001","119", "97674223", "1195524421"},{"123","456","789"},{"12","123","1235","567","88"}};

    for(int i=0; i< test.size();i++){
        if(!solution(test[i])){
            printf("False\n");
        }
        else{
            printf("True\n");
        }
    }

    return 0;
}