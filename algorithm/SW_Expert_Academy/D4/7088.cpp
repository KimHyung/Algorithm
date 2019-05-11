#include <iostream>
#include <vector>
using namespace std;

int main(){
    int test_case;
    int T;
    // short dp[1000001][4];
    vector<vector<int>> dp;
    int n, q, v, l, r, kind1, kind2, kind3;
    scanf("%d", &T);
    dp.resize(1000001,vector<int>(4,0));
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d %d", &n, &q);
        
        for (int i = 1; i <= n; i++) {
            scanf("%d", &v);
            if (v == 1) {
                dp[i][1] = dp[i-1][1] + 1;
                dp[i][2] = dp[i-1][2];
                dp[i][3] = dp[i-1][3];
            }
            else if (v == 2) {
                dp[i][1] = dp[i-1][1];
                dp[i][2] = dp[i-1][2] + 1;
                dp[i][3] = dp[i-1][3];
            }
            else {
                dp[i][1] = dp[i-1][1];
                dp[i][2] = dp[i-1][2];
                dp[i][3] = dp[i-1][3] + 1;
            }
        }
        
        printf("#%d\n", test_case);
        
        for (int i = 1; i <= q; i ++) {
            scanf("%d %d", &l, &r);
            kind1 = dp[r][1] - dp[l-1][1];
            kind2 = dp[r][2] - dp[l-1][2];
            kind3 = dp[r][3] - dp[l-1][3];
            printf("%d %d %d\n", kind1, kind2, kind3);
        }
        dp.clear();
    }
    return 0;
}
