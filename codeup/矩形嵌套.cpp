#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
const int maxn = 1010;
int G[maxn][maxn];
int dp[maxn];

struct rect{
    int width,length;
}node[maxn];

void createG(int n){
    fill(G[0], G[0]+maxn*maxn, 0);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(node[i].width > node[j].width && node[i].length > node[j].length){
                G[i][j] = 1;
            }
        }
    }
}

int DP(int i, int n){
    if(dp[i] > 0) return dp[i];
    for(int j = 0;j < n;j++){
        if(G[i][j] != 0){
            dp[i] = max(dp[i], DP(j,n) + G[i][j]);
        }
    }
    return dp[i];
}

int main(){
    int n;
    scanf("%d",&n);
    int recnum;
    for(int i = 0;i < n;i++){
        scanf("%d",&recnum);
        int w,l;
        for(int j = 0;j < recnum;j++){
            scanf("%d%d",&w,&l);
            if(w > l) swap(w,l);
            node[j].length = l;
            node[j].width = w;
        }
        createG(recnum);
        fill(dp, dp+maxn, 0);
        int ans = 0;
        for(int j = 0;j < recnum;j++){
            ans = max(ans, DP(j,recnum));
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
