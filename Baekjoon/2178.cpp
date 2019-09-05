#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[100][100];
vector<vector<bool>> visit;
int N,M;
int dx[4] = {1, -1, 0, 0};    
int dy[4] = {0, 0, -1, 1};    
 
int bfs() {
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0,0),1));   
    visit[0][0] = 1;
 
    while(!q.empty()) {
        
        int x = q.front().first.second;
        int y = q.front().first.first;
        int z = q.front().second;
        q.pop();
 
        if(x == M-1 && y == N-1)
            return z;
 
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if(nx < 0 || ny < 0 || nx >= M || ny >= N)
                continue;
            if(visit[ny][nx] == 1)
                continue;
            if(map[ny][nx] != '1')
                continue;
            
            q.push(make_pair(make_pair(ny,nx),z+1));
            visit[ny][nx] = 1;
        }
    }
}


int main(){
	scanf("%d %d",&N,&M);
	visit.resize(N,vector<bool>(M,false));
	for(int i=0;i<N;i++){
		cin >> map[i];

	}
	cout << bfs() <<endl;

	return 0;
}