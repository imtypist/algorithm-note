#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
const int maxn = 51;
int G[maxn][maxn],n;
int inDegree[maxn];

void topologicalSort(){
    priority_queue<int> q;
    queue<int> r;
    int num = 0;
    for(int i = 0;i < n;i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.top();
        q.pop();
        r.push(u);
        for(int v = 0;v < n;v++){
            if(G[u][v] == 1){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }
        num++;
    }
    if(num == n){
        while(!r.empty()){
            printf("%d ",r.front());
            r.pop();
        }
        printf("\n");
    }else{
        printf("ERROR\n");
    }
}

int main(){
    scanf("%d",&n);
    memset(inDegree, 0, sizeof(inDegree));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            scanf("%d",&G[i][j]);
            if(G[i][j] == 1){
                inDegree[j]++;
            }
        }
    }
    topologicalSort();
    return 0;
}
