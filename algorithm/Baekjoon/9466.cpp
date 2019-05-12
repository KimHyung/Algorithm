#include <iostream>
#include <vector>

using namespace std;

vector<int> s;
vector<bool> visited;
vector<bool> finished;
int N,cnt;

void dfs(int curr){
	visited[curr] = true;
	int next = s[curr];
	if(visited[next]){
		if(!finished[next]){
			for(int tmp=next; tmp!=curr; tmp=s[tmp]) cnt++;
				cnt++;
		}
	}
	else{
		dfs(next);
	}
	finished[curr] = true;
}

int main(){
	int t,T;
	scanf("%d",&T);
	t=1;
	while(t<=T){
		scanf("%d",&N);
		s.resize(N,0);
		visited.resize(N,false);
		finished.resize(N,false);
		for(int i=0; i<N;i++){
			scanf("%d",&s[i]);
			s[i]--;
		}
		cnt=0;
		for(int i=0; i<N;i++){
			if(!visited[i])dfs(i);
		}
		printf("%d\n",N-cnt);
		s.clear();
		visited.clear();
		finished.clear();
		t++;
	}
	return 0;
}