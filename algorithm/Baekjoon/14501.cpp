#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> TP;
int N;
int MAX=0;

void dfs(int curr, int temp){
	if(curr > N){
		return ;
	}
	if(curr == N){
		MAX = max(MAX, temp);
		return ;
	}
	dfs(curr+1, temp);
	dfs(curr + TP[curr].first, temp + TP[curr].second);
}

int main(){
	cin >> N;
	TP.resize(N,{0,0});
	for(int i=0; i<N;i++){
		cin>> TP[i].first >> TP[i].second;
	}
	dfs(1,0);
	dfs(TP[0].first,TP[0].second);
	cout << MAX <<endl;
	return 0;
}