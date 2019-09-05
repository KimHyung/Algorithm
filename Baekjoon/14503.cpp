#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
//simulation
using namespace std;

int N,M;
vector<vector<int>> MAP;
vector<vector<bool>> clean;
int r,c,d;

// direction >>> 0:N, 1:E, 2:S, 3:W
pair<int,int> dir[4] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
int ans=1;

int change_dir(int tmp){
	if(tmp == 0){
		return 3;
	}
	else if(tmp == 1){
		return 0;
	}
	else if(tmp == 2){
		return 1;
	}
	else{
		return 2;
	}
}

int back(int tmp){
	if(tmp == 0 ){
		return 2;
	}
	else if(tmp == 1){
		return 3;
	}
	else if(tmp == 2){
		return 0;
	}
	else{
		return 1;
	}
}

void F(){
	int cnt;
	queue<pair<int,int>> robot;
	robot.push(make_pair(r,c));
	while(!robot.empty()){
		cnt=0;
		r = robot.front().first;
		c = robot.front().second;
		robot.pop();
		// printf("present: x: %d, y: %d, d:%d cnt:%d\n",r,c,d,cnt);
		while(cnt<4){
			d = change_dir(d);
			int next_x = r + dir[d].first;
			int next_y = c + dir[d].second;
			// printf("next>> x:%d y: %d d: %d cnt:%d\n",next_x,next_y,d,cnt);
			if(next_x >= 0 && next_x < N && next_y >=0 && next_y <M){
				if(MAP[next_x][next_y] ==0 && clean[next_x][next_y] == false){
					clean[next_x][next_y] = true;
					robot.push(make_pair(next_x,next_y));
					ans++;
					break;
				}
			}
			cnt++;
		}
		if(robot.empty()){
			int b = back(d);
			int next_x = r + dir[b].first;
			int next_y = c + dir[b].second;
			// printf("back>> x:%d y:%d d:%d\n",next_x,next_y,b);
			if(next_x >= 0 && next_x < N && next_y >=0 && next_y <M){
				if(MAP[next_x][next_y]==0){
					robot.push(make_pair(next_x,next_y));
				}
			}
		}
	} 
}

int main(){
	cin >> N >> M;
	cin >> r >> c >> d;
	MAP.resize(N,vector<int>(M));
	clean.resize(N,vector<bool>(M,false));
	clean[r][c] = true;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> MAP[i][j];
		}
	}
	F();
	cout << ans << endl;	
	return 0;
}