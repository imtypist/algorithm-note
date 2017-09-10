#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 51;
const int INF = 1000000000;
int G[maxn][maxn], d[maxn];
int N,st;
bool vis[maxn] = {false};

void dijkstra(){
    d[st] = 0;
    for(int i = 0;i < N;i++){
        int u = 0, MIN = INF;
        for(int j = 0;j < N;j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0;v < N;v++){
            if(G[u][v] != 0 && G[u][v] + d[u] < d[v]){
                d[v] = G[u][v] + d[u];
            }
        }
    }
}


int main(){
    scanf("%d%d",&N,&st);
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            scanf("%d",&G[i][j]);
        }
    }
    fill(d, d + maxn, INF);
    dijkstra();
    for(int i = 0;i < N;i++){
        if(i == st) continue;
        if(d[i] == INF) printf("-1 ");
        else printf("%d ",d[i]);
    }
    printf("\n");
    return 0;
}
