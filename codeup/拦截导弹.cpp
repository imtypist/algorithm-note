#include <cstdio>

const int maxn = 30;

int dp[maxn],missile[maxn];

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        if(n == 0) break;
        for(int i = 0;i < n;i++){
            scanf("%d",&missile[i]);
        }
        for(int i = 0;i < n;i++){
            dp[i] = 1;
            for(int j = 0;j < i;j++){
                if(missile[i] <= missile[j] && (dp[j] + 1 > dp[i])){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        int MAX = dp[0];
        for(int i = 1;i < n;i++){
            if(dp[i] > MAX){
                MAX = dp[i];
            }
        }
        printf("%d\n",MAX);
    }
    return 0;
}
