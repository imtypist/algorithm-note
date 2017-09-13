#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 110;
int N;
int p[maxn];
int dp1[maxn],dp2[maxn];

int main(){
    while(scanf("%d",&N) != EOF){
        if(N == 0) break;
        for(int i = 1;i <= N;i++){
            scanf("%d",&p[i]);
        }
        int MAX = -1;
        for(int k = 1;k <= N;k++){
            int sum1 = -1;
            for(int i = 1;i <= k;i++){
                dp1[i] = 1;
                for(int j = 1;j < i;j++){
                    if(p[i] > p[j] && (dp1[j]+1>dp1[i])){
                        dp1[i] = dp1[j] + 1;
                    }
                }
                sum1 = max(sum1,dp1[i]);
            }
            int sum2 = -1;
            for(int i = k;i <= N;i++){
                dp2[i] = 1;
                for(int j = k;j < i;j++){
                    if(p[i] < p[j] && (dp2[j]+1>dp2[i])){
                        dp2[i] = dp2[j] + 1;
                    }
                }
                sum2 = max(sum2,dp2[i]);
            }
            MAX = max(MAX,sum1+sum2);
        }
        printf("%d\n",N-MAX+1);
    }
    return 0;
}
