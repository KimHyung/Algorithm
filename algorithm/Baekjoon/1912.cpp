#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int num[100001];
    int sum[100001];
    int tmp,n;
    scanf("%d", &n);    
    for(int i=0; i<n; i++){
        scanf("%d", &num[i]);
    }
    sum[0]=num[0];
    tmp = num[0];
    for(int i=1; i<n; i++){
    	sum[i] = max(sum[i-1]+num[i],num[i]);
    	tmp = max(sum[i],tmp);
    }
    printf("%d\n", tmp);
    return 0;
}