#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int V,N;
long long w[maxn],dp[maxn];

int main(){
    while(scanf("%d%d",&N,&V) != EOF){
        for(int i = 1;i <= N;i++){
            scanf("%lld",&w[i]);
        }
        fill(dp, dp+maxn, 0);
        for(int i = 1;i <= N;i++){
            for(int v = w[i];v <= V;v++){
                dp[v] = max(dp[v], dp[v-w[i]]+w[i]);
            }
        }
        printf("%lld\n",dp[V]);
    }
    return 0;
}
