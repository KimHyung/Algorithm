#include <iostream>

using namespace std;

int main(){
	int t,T;
	int S,E,M;
	cin >> T;
	t=1;
	while(t<=T){
		cin >> S >> E >> M;
		int ts = E;
		int tm = E;
		int ans = E;
		int div = 24;
		while(true){
			if(ts == S && tm == M)
				break;
			ts +=div;
			if(ts > 365)
				ts%=365;
			tm +=div;
			if(tm > 29)
				tm%=29;
			ans +=div;
		}
		printf("#%d %d\n",t,ans);
		t++;	
	}	
	return 0;
}