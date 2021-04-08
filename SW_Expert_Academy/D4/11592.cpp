#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(int dist, int N, int A_pos, int A_vel, int B_pos, int B_vel, int i){
    double ans;
    if(B_vel!=0){
        double t_A = double(dist-A_pos)/double(A_vel);
        double t_B = double(dist-B_pos)/double(B_vel);
        if(t_A>t_B){
            ans = double(dist/t_A);
        }
        else{
            ans = double(dist/t_B);
        }
    }
    else{
        double t_A = double(dist-A_pos)/double(A_vel);
        ans = double(dist/t_A);
    }
    printf("#%d %f\n",i+1,ans);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
    vector<pair<int,int>> state;
    vector<pair<int,int>> horse;
    int ptr=0;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int dis;
        int N;
        cin >> dis;
        cin >> N;
        state.push_back(make_pair(dis,N));
        for(int i=0;i<N;i++){
            int pos;
            int vel;
            cin >> pos;
            cin >> vel;
            horse.push_back(make_pair(pos,vel));
        }
	}
    
    // for(int i=0;i<state.size();i++){
    //     printf("case%d dis:%d, horse:%d\n",i+1,state[i].first,state[i].second);
    //     for(int j=0; j<state[i].second; j++,ptr++){
    //         printf("#%d pos:%d, speed:%d\n",j+1,horse[ptr].first,horse[ptr].second);
    //     }

    // }
    ptr=0;
    for(int i=0; i<T;i++){
        int dist = state[i].first;
        int horse_size = state[i].second;
        int A_pos = horse[ptr].first;
        int A_vel = horse[ptr].second;
        ptr++;
        if(horse_size>1){
            int B_pos = horse[ptr].first;
            int B_vel = horse[ptr].second;
            ptr++;
            solve(dist, horse_size, A_pos, A_vel, B_pos, B_vel,i);
        }
        else{
            solve(dist, horse_size, A_pos, A_vel, dist, 0,i);
        }
    }

	return 0;
}