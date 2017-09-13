#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 5;
int dp[maxn],w[maxn];

int main(){
    int sum = 0;
    for(int i = 0;i < maxn;i++){
        scanf("%d",&w[i]);
        sum += w[i];
        if(w[i] == 0){
            printf("ERROR\n");
            break;
        }
    }
    int temp = sum / 2;
    memset(dp, 0, sizeof(dp));
    for(int i = 0;i < maxn;i++){
        for(int v = temp;v >= w[i];v--){
            dp[v] = max(dp[v], dp[v-w[i]] + w[i]);
        }
    }
    if(dp[temp] > sum - dp[temp]){
        printf("%d %d\n",sum - dp[temp],dp[temp]);
    }else{
        printf("%d %d\n",dp[temp], sum - dp[temp]);
    }
    return 0;
}
