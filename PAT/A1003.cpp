#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 510;
const int INF = 1000000000;
int N,M;
int teamNum[maxn];
int G[maxn][maxn];
int w[maxn];
int d[maxn];
int roads[maxn];
bool vis[maxn] = {false};

void Dijkstra(int c1){
    fill(d,d+maxn,INF);
    memset(roads, 0, sizeof(roads));
    memset(w, 0, sizeof(w));
    d[c1] = 0;
    w[c1] = teamNum[c1];
    roads[c1] = 1;
    for(int i = 0;i < N;i++){
        int u = -1,MIN = INF;
        for(int j = 0;j < N;j++){
            if(d[j] < MIN && vis[j] == false){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0;v < N;v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    roads[v] = roads[u];
                    w[v] = w[u] + teamNum[v];
                }else if(d[u] + G[u][v] == d[v]){
                    roads[v] += roads[u];
                    if(w[v] < w[u] + teamNum[v]){
                        w[v] = w[u] + teamNum[v];
                    }
                }
            }
        }
    }
}

int main(){
    int c1,c2;
    scanf("%d%d%d%d",&N,&M,&c1,&c2);
    for(int i = 0;i < N;i++){
        scanf("%d",&teamNum[i]);
    }
    int L,a,b;
    fill(G[0],G[0] + maxn*maxn, INF);
    for(int i = 0;i < M;i++){
        scanf("%d%d%d",&a,&b,&L);
        G[a][b] = G[b][a] = L;
    }
    Dijkstra(c1);
    printf("%d %d\n",roads[c2],w[c2]);
    return 0;
}
