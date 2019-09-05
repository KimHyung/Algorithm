#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A;
int op[4] ={0,0,0,0};
int N;
int Max_N=-1000000005;
int Min_N=1000000005;

int dfs(int curr, int temp){
	if(curr == N){
		Max_N = max(Max_N, temp);
		Min_N = min(Min_N, temp);
		return 0;
	}

	if(op[0]>0){
		op[0]--;
		dfs(curr+1, temp + A[curr]);
		op[0]++;
	}
	if(op[1]>0){
		op[1]--;
		dfs(curr+1, temp - A[curr]);
		op[1]++;
	}
	if(op[2]>0){
		op[2]--;
		dfs(curr+1, temp * A[curr]);
		op[2]++;
	}
	if(op[3]>0){
		op[3]--;
		dfs(curr+1, temp / A[curr]);
		op[3]++;
	}
	return 0;

}

int main(){
	scanf("%d", &N);
	A.resize(N,0);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(int i=0; i<4;i++){
		scanf("%d", &op[i]);
	}

	dfs(1, A[0]);
	printf("%d\n%d\n",Max_N,Min_N);

	return 0;
}

