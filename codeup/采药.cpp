#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int T,M;
int dp[maxn],w[maxn],c[maxn];

int main(){
    scanf("%d%d",&T,&M);
    for(int i = 1;i <= M;i++){
        scanf("%d%d",&w[i],&c[i]);
    }
    for(int i = 1;i <= M;i++){
        for(int v = T;v >= w[i];v--){
            dp[v] = max(dp[v], dp[v-w[i]]+c[i]);
        }
    }
    printf("%d\n",dp[T]);
    return 0;
}
