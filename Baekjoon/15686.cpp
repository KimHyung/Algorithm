//chicken delivery

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,ans;


vector< vector<int> >map;
vector< pair<int,int> > hof;
vector< pair<int,int> > home;
vector< bool > open;

void DFS(int cnt, int chicken){
	if(cnt > hof.size())
		return;
	if(chicken == M){
		int tmp = 0; 
		for(int i=0; i<home.size(); i++){
			int dist = 2147483647;
			for(int j=0; j<hof.size(); j++){
				if(open[j]){
					int d = abs(home[i].first - hof[j].first)+abs(home[i].second-hof[j].second);
					dist = min(dist,d);
				}
			}
			tmp += dist;
		}
		ans = min(ans,tmp);
		return;
	}
	open[cnt] = true;
	DFS(cnt+1, chicken+1);
	open[cnt] = false;
	DFS(cnt+1, chicken);

}

int main(){
	cin >> N >> M;
	map.resize(N,vector<int>(N));
	for(int i=0; i<N;i++){
		for(int j=0; j<N; j++){
			cin >> map[i][j];
			if(map[i][j]==2){
				hof.push_back(make_pair(i,j));
			}
			else if(map[i][j]==1){
				home.push_back(make_pair(i,j));
			}	
		}
	}
	open.resize(hof.size(),false);
	ans = 2147483647;
	DFS(0,0);
	cout << ans << endl;
}