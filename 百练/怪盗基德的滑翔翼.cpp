#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 110;
int dp[maxn],height[maxn];

int main(){
    int k,n;
    scanf("%d",&k);
    for(int i = 0;i < k; i++){
        scanf("%d",&n);
        for(int j = 0;j < n; j++){
            scanf("%d",&height[j]);
        }
        int ans = -1;
        for(int j = 0;j < n;j++){
            dp[j] = 1;
            for(int m = 0;m < j;m++){
                if(height[j] >= height[m] && (dp[m] + 1 > dp[j])){
                    dp[j] = dp[m] + 1;
                }
            }
            ans = max(ans, dp[j]);
        }
        for(int j = 0;j < n;j++){
            dp[j] = 1;
            for(int m = 0;m < j;m++){
                if(height[j] <= height[m] && (dp[m] + 1 > dp[j])){
                    dp[j] = dp[m] + 1;
                }
            }
            ans = max(ans, dp[j]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
