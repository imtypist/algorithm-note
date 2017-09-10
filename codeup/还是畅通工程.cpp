#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 110;
const int INF = 1000000000;
int G[maxn][maxn];
int d[maxn];
bool vis[maxn] = {false};

int prim(int n){
    fill(d, d + maxn, INF);
    int sum = 0;
    d[1] = 0;
    for(int i = 1;i <= n;i++){
        int u = -1, MIN = INF;
        for(int j = 1;j <= n;j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return -1;
        vis[u] = true;
        sum += d[u];
        for(int v = 1;v <= n;v++){
            if(vis[v] == false && G[u][v] < d[v] && G[u][v] != INF){
                d[v] = G[u][v];
            }
        }
    }
    return sum;
}

int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(n == 0) break;
        int a,b,w;
        fill(G[0], G[0] + maxn*maxn, INF);
        for(int i = 0;i < n*(n-1)/2;i++){
            scanf("%d %d %d",&a,&b,&w);
            G[a][b] = G[b][a] = w;
        }
        printf("%d\n",prim(n));
    }
    return 0;
}
