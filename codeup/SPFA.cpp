#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 510;
const int INF = 1000000000;
struct node{
    int dis,v;
};
vector<node> G[maxn];
int n, d[maxn], num[maxn];
bool inq[maxn];

bool SPFA(int st){
    queue<int> q;
    memset(num, 0, sizeof(num));
    fill(inq, inq + maxn, false);
    fill(d, d + maxn, INF);
    q.push(s);
    inq[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        inq[u] = false;
        for(int i = 0;i < G[u].size();i++){
            int dis = G[u][i].dis;
            int v = G[u][i].v;
            if(dis + d[u] < d[v]){
                d[v] = dis + d[u];
                if(inq[v] == false){
                    q.push(v);
                    inq[v] = true;
                    num[v]++;
                    if(num[v] > n-1) return false;
                }
            }
        }
    }
    return true;
}
