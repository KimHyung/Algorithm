#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<vector<int>> space;
vector<vector<int>> test;
vector<int>dp;
// int virus[24];
vector<int>virus;
int count_virus=1000;
int count_virus_temp=1000;

int connect_virus(int x, int y){
	// printf("[%d %d]: %d,\n",x,y,test[x][y]);
	if(test[x][y]==2){
		count_virus++;
	}
	if(x != 0){
		if(test[x-1][y]==0){
			test[x-1][y]=2;
			connect_virus(x-1,y);			
		}
	}
	if(x != N-1){
		if(test[x+1][y]==0){
			test[x+1][y]=2;
			connect_virus(x+1,y);
		}
	}
	if(y != 0){
		if(test[x][y-1]==0){
			test[x][y-1]=2;
			connect_virus(x,y-1);
		}
	}
	if(y != M-1){
		if(test[x][y+1]==0){
			test[x][y+1]=2;
			connect_virus(x,y+1);
		}
	}
	return 0;
}
void find_virus(){
	int i,j;
	test = space;
	// printf("inf find_virus func\n");
	for(int k=0;k<N*M;k++){
		if(virus[k]==2){
			i = k/M;
			j = k%M;
			// printf("%d,%d \n",i,j);
			// count_virus++;
			connect_virus(i,j);
		}	
	}	
}
int main(){
	int tmp;
	int wall=0;
	scanf("%d %d",&N,&M);	
	space.resize(N,vector<int>(M,-1));
	test.resize(N,vector<int>(M,-1));
	tmp = N*M;
	virus.resize(tmp,-1);
	// fill_n(virus,24,0);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d",&space[i][j]);
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(space[i][j]==2){
				tmp = (M*i)+j;
				virus[tmp]=2;
			}
			if(space[i][j]==1){
				tmp = (M*i)+j;
				virus[tmp]=1;
				wall= wall +1;
			}
			if(space[i][j]==0){
				tmp = (M*i)+j;
				dp.push_back(tmp);
			}
		}
	}
	int i,j,k;
	int n1,n2,n3;
	int m1,m2,m3;
	int count_temp =0;
	for(i=0;i<dp.size()-2;i++){
		for(j=i+1;j<dp.size()-1;j++){
			for(k=j+1;k<dp.size()-0;k++){
				n1 =dp[i]/M;
				n2 =dp[j]/M;
				n3 =dp[k]/M;
				m1 =dp[i]%M;
				m2 =dp[j]%M;
				m3 =dp[k]%M;
				space[n1][m1]=1;
				space[n2][m2]=1;
				space[n3][m3]=1;
				count_temp++;
				count_virus_temp = count_virus;
				count_virus=0;
				find_virus();
				space[n1][m1]=0;
				space[n2][m2]=0;
				space[n3][m3]=0;
				if(count_virus_temp < count_virus){
					count_virus = count_virus_temp; 
				}
			}
		}
	}
	printf("%d\n",(N*M-(wall+3)-count_virus));
	return 0;
}