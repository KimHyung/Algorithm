#include <iostream>
#include <vector>

using namespace std;

struct board{
    char map_[4][4];
};

bool checkRow(struct board game, int col, char ans){
    for(int i=0; i<4; i++){
        if(game.map_[i][col]!=ans){
            if(game.map_[i][col] == 'T'){
                continue;
            }
            else{
                return false;
            }
        }
    }
    return true;
}

bool checkCol(struct board game, int row, char ans){
    for(int i=0; i<4; i++){
        if(game.map_[row][i] != ans){
            if(game.map_[row][i] == 'T'){
                continue;
            }
            else{
                return false;
            }
        }
    }
    return true;
}

bool checkCross(struct board game, int row, int col, char ans){
    if(row==col){
        for(int i=0; i<4; i++){
            if(game.map_[i][i] != ans){
                if(game.map_[i][i] == 'T'){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
    else{
        for(int i=0,j=3; i<4; i++,j--){
            if(game.map_[i][j] != ans){
                if(game.map_[i][j] == 'T'){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
}

void solve(struct board game, int index){
    bool row=false;
    bool col=false;
    bool cross=false;
    int cnt=0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(game.map_[i][j]=='X'||game.map_[i][j]=='O'){
                row = checkRow(game, j, game.map_[i][j]);
                col = checkCol(game, i, game.map_[i][j]);
                if( (i==0&&j==0)||(i==3&&j==0)||(i==0&&j==3)||(i==3&&j==3) ){
                    cross=checkCross(game,i,j,game.map_[i][j]);
                }
            }
            if(game.map_[i][j]=='.'){
                cnt++;
            }
            if(row || col || cross){
                printf("#%d %c won\n",index+1,game.map_[i][j]);    
                return;
            }
        }
    }
    if(cnt==0){
        printf("#%d Draw\n",index+1);
    }
    else{
        printf("#%d Game has not completed\n",index+1);
    }
}

int main(int argc, char** argv){
    int test_case;
    int T;
    vector<board> input;
    cin >> T;
    struct board tmp_;
    for(test_case=1;test_case<=T;++test_case){
        for(int i=0; i<4;i++){
            for(int j=0; j<4; j++){
                cin >> tmp_.map_ [i][j];
            }
        }
        input.push_back(tmp_);
    }
    
    for(int i=0; i<input.size();i++){
        solve(input[i],i);
    }

    return 0;
}