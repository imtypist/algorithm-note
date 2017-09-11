#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 20010;
int V,n;
int w[maxn];
int dp[maxn];

int main(){
    scanf("%d%d",&V,&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&w[i]);
    }
    for(int i = 1;i <=n;i++){
        for(int v = V;v >= w[i];v--){
            dp[v] = max(dp[v], dp[v-w[i]]+w[i]);
        }
    }
    printf("%d\n",V-dp[V]);
    return 0;
}
