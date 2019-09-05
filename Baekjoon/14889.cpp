#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<vector<int>> player;
vector<bool> used;

int ans=100000000;

void dfs(int curr, int cnt){
	if(cnt == N/2){
		vector<int> link_player, start_player;
		int link_ans=0, start_ans=0;
		for(int i=0;i<N;i++){
			if(used[i])
				start_player.push_back(i);
			else
				link_player.push_back(i);
		}
		for(int i=0; i<start_player.size();i++){
			for(int j=0; j<link_player.size();j++){
				link_ans = link_ans + player[link_player[i]][link_player[j]];
				start_ans = start_ans + player[start_player[i]][start_player[j]];
			}
		}
		ans = min(ans, abs(start_ans - link_ans));
		return;
	}

	for(int i = curr+1;i<N;i++){
		if(used[i]==false){
			used[i]=true;
			dfs(i,cnt+1);
			used[i]=false;
		}
	}
}

int main(){
	cin >> N;
	player.resize(N,vector<int>(N,0));
	used.resize(N+1,false);
	for(int i=0; i<N;i++)
		for(int j=0; j<N;j++)
			cin >> player[i][j];

	dfs(0,0);
	cout << ans <<endl;

	return 0;
}