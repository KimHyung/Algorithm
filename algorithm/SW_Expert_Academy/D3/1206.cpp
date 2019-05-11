
#include <iostream>
#include <vector>

using namespace std;

const int Height_MAX = 255;
const int Wide_MAX = 1000;

vector<vector<bool>> building;

bool F(int N ,int P) {
	if (N == 0) {
		if (building[N + 1][P] || building[N + 2][P])
			return false;
		else
			return true;
	}
	if (N == 1) {
		if (building[N + 1][P] || building[N + 2][P] || building[N - 1][P])
			return false;
		else
			return true;
	}
	if (N == building.size() - 1) {
		if (building[N - 1][P] || building[N - 2][P])
			return false;
		else
			return true;
	}
	if (N == building.size() - 2) {
		if (building[N + 1][P] || building[N - 1][P] || building[N - 2][P])
			return false;
		else
			return true;
	}
	if (building[N + 1][P] || building[N + 2][P] || building[N - 1][P] || building[N - 2][P])
		return false;
	else
		return true;
}

int main()
{
	
	int N;
	int temp;
	int result;
	int t = 1, T = 10;
	while(t<=T){
        result=0;
		scanf("%d", &N);
		building.resize(N);	
		for (int i = 0; i < N; i++) {
			building[i].resize(Height_MAX, false);
			cin>> temp;
			fill(building[i].begin(), building[i].begin() + temp, true);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j <Height_MAX; j++) {
				if (building[i][j] == false) {
					break;
			}
				else {
					if (F(i, j))
						result++;
				}
			}
		}
 
		for (int i = 0; i < N; i++) {
			building[i].clear();
		}
		cout <<"#"<<t<<" "<< result << endl;
		t++;
	}
}

