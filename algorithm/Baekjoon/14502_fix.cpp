#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct dir{
	int y,x;
};

dir moveDir[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int N,M;
vector<vector<int>> lab;
vector<vector<int>> temp;
vector<pair<int,int>> safety;
int ans=0;

void spred(){
	int empty = 0;
	vector<vector<int>> afterSpread;
	afterSpread = temp;
	queue<pair<int,int>> virus;
	for(int i=0;i<N;i++){
		for(int j=0; j<M;j++){
			if(afterSpread[i][j]==2)
				virus.push(make_pair(i,j));
		}
	}
	while(!virus.empty()){
		int y = virus.front().first;
		int x = virus.front().second;
		virus.pop();
		for(int i=0; i<4;i++){
			int nextX = x+moveDir[i].x;
			int nextY = y+moveDir[i].y;
			if(0 <= nextY && nextY < N && 0 <= nextX && nextX < M) //범위 내
                 if (afterSpread[nextY][nextX] == 0) //빈칸이라면
                 {
                          afterSpread[nextY][nextX] = 2; //바이러스 감염
                          virus.push(make_pair(nextY, nextX));

                 }
		}
	}

	for(int i = 0; i< N;i++){
		for(int j =0 ;j<M;j++){
			if(afterSpread[i][j] == 0){
				empty++;
			}	
		}
	}
	ans = max(ans,empty);
}


int main(){
	cin >> N >> M;
	lab.resize(N,vector<int>(M));
	temp.resize(N,vector<int>(M));
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> lab[i][j];
			if(lab[i][j]==0){
				safety.push_back({i,j});
			}
		}
	}
	temp = lab;
	int cnt=1;
	for(int i=0;i<safety.size()-2;i++){
		temp[safety[i].first][safety[i].second]=1;
		for(int j=i+1;j<safety.size()-1;j++){
			temp[safety[j].first][safety[j].second]=1;
			for(int k=j+1;k<safety.size();k++){
				temp[safety[k].first][safety[k].second]=1;
				spred();
				temp[safety[k].first][safety[k].second]=0;
			}
			temp[safety[j].first][safety[j].second]=0;
		}
		temp[safety[i].first][safety[i].second]=0;
	}	
	cout << ans <<endl;

	return 0;
}