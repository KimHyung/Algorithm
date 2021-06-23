#include <iostream>
#include <vector>
using namespace std;

long long solution(vector<vector<int> > rectangles)
{
    long long answer = -1;
    int rec_size=0;
    for(int i=0; i<rectangles.size();i++){
        int x = rectangles[i][2]-rectangles[i][0];
        int y = rectangles[i][3]-rectangles[i][1];
        rec_size+=x*y;
    }
 
    printf("%d\n",rec_size);
    return answer;
}

int main(){
    vector<vector<int>> rectangles = {{1, 1, 6, 5}, {2, 0, 4, 2}, {2, 4, 5, 7},{4, 3, 8, 6}, {7, 5, 9, 7}}; 
    long long answer = 38;
    if(answer == solution(rectangles)){
        printf("DOH!\n");
    }
    else{
        printf("NOPE!\n");
    }
    return 0;
}