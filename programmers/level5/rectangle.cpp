#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

long long solution(vector<vector<int> > rectangles)
{
    long long answer = -1;
    long long x_max=0, y_max=0;
    int** map;
    //1.find max size of map
    for(int i=0; i<rectangles.size();i++){
        if(rectangles[i][2]>x_max)  x_max = rectangles[i][2];
        if(rectangles[i][3]>y_max)  y_max = rectangles[i][3];
    }
    //2.동적할당
    map = (int **) malloc ( sizeof(int *) * y_max);
    map[0] = (int *) malloc ( sizeof(int) * x_max*y_max );
    for( int i=1; i<y_max; i++){
        map[i] = map[i-1] + x_max;
    }
    for(int i=0; i<rectangles.size();i++){
        for(int j=rectangles[i][1]; j<rectangles[i][3];j++){
            for(int k=rectangles[i][0]; k<rectangles[i][2];k++){
                if(map[j][k] != 1){
                    answer++;
                    map[j][k]=1;
                }
                
            }
        }
    }


    for(int i=0; i<y_max;i++){
        for(int j=0; j<x_max; j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }

    free(map[0]);
    free(map);
    answer++;
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