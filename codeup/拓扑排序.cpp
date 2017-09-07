// AOV Activity On Vertex
#include <cstdio>
const int maxn = 110;
vector<int> G[maxn];
int n, inDegree[maxn];

bool topologicalSort(){
    int num = 0;
    queue<int> q;
    for(int i = 0;i < n;i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = .front();
        q.pop();
        for(int i = 0;i < G[u].size();i++){
            int v = G[u][i];
            inDegree[v]--;
            if(inDegree[v] == 0){
                q.push(v);
            }
        }
        //G[u].clear();
        num++;
    }
    if(num == n) return true;
    else return false;
}
