#include <cstdio>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

const int maxn = 20;
const int INF = 1000000000;
map<char, int> charToInt;
map<int, char> intToChar;
stack<int> topOrder;
int G[maxn][maxn];
int inDegree[maxn],ve[maxn],vl[maxn];

bool topologicalSort(int n){
    queue<int> q;
    for(int i = 0;i < n;i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topOrder.push(u);
        for(int v = 0;v < n;v++){
            if(G[u][v] != INF){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                }
                if(ve[u] + G[u][v] > ve[v]){
                    ve[v] = ve[u] + G[u][v];
                }
            }
        }
    }
    if(topOrder.size() == n) return true;
    else return false;
}

void criticalPath(int n){
    fill(ve, ve+maxn, 0);
    if(topologicalSort(n) == false){
        return;
    }
    int maxLength = 0;
    for(int i = 0;i < n;i++){
        if(ve[i] > maxLength){
            maxLength = ve[i];
        }
    }
    fill(vl, vl+n, maxLength);
    while(!topOrder.empty()){
        int u = topOrder.top();
        topOrder.pop();
        for(int v = 0;v < n;v++){
            if(G[u][v] != INF){
                if(vl[v] - G[u][v] < vl[u]){
                    vl[u] = vl[v] - G[u][v];
                }
            }
        }
    }

    for(int u = 0;u < n;u++){
        for(int v = 0;v < n;v++){
            if(G[u][v] != INF){
                int w = G[u][v];
                int e = ve[u], l = vl[v] - w;
                if(e == l){
                    printf("(%c,%c) ",intToChar[u],intToChar[v]);
                }
            }
        }
    }
    printf("%d\n",maxLength);
}

int main(){
    int n,x,y;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d%d",&x,&y);
        fill(G[0], G[0]+maxn*maxn, INF);
        fill(inDegree, inDegree+maxn, 0);
        char c;
        getchar();
        for(int j = 0;j < x;j++){
            scanf("%c",&c);
            charToInt[c] = j;
            intToChar[j] = c;
        }
        char a,b;
        int d;
        for(int j = 0;j < y;j++){
            getchar();
            scanf("%c %c %d",&a,&b,&d);
            G[charToInt[a]][charToInt[b]] = d;
            inDegree[charToInt[b]]++;
        }
        criticalPath(x);
    }
    return 0;
}
