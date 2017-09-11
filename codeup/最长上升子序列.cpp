#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int dp[maxn],a[maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    int ans = -1;
    for(int i = 0;i < n;i++){
        dp[i] = 1;
        for(int j = 0;j < i;j++){
            if((a[j] < a[i]) && (dp[j] + 1 > dp[i])){
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}
