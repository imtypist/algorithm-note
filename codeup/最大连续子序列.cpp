#include <cstdio>

const int maxn = 10010;
int p[maxn],dp[maxn],st[maxn];

int main(){
    int k;
    while(1){
        scanf("%d",&k);
        if(k == 0) break;
        bool neg = true;
        for(int i = 0;i < k;i++){
            scanf("%d",&p[i]);
            if(p[i] >= 0) neg = false;
        }
        if(neg){
            printf("0 %d %d\n",p[0],p[k-1]);
            continue;
        }else{
            dp[0] = p[0];
            st[0] = 0;
            for(int i = 1;i < k;i++){
                if(dp[i-1]+p[i] > p[i]){
                    dp[i] = dp[i-1] + p[i];
                    st[i] = st[i-1];
                }else{
                    dp[i] = p[i];
                    st[i] = i;
                }
            }
            int MAX = dp[0],u = 0;
            for(int i = 1;i < k;i++){
                if(dp[i] > MAX){
                    MAX = dp[i];
                    u = i;
                }
            }
            printf("%d %d %d\n",dp[u],p[st[u]],p[u]);
        }
    }
    return 0;
}
