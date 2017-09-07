// AOE Activity On Edge
stack<int> topOrder;
bool topologicalSort(){
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
        for(int i = 0;i < G[u].size();i++){
            int v = G[u][i].v;
            inDegree[v]--;
            if(inDegree[v] == 0){
                q.push(v);
            }
            if(ve[u] + G[u][i].w > ve[v]){
                ve[v] = ve[u] + G[u][i].w;
            }
        }
    }
    if(topOrder.size() == n) return true;
    else return false;
}

int criticalPath(){
    memset(ve, 0, sizeof(ve));
    if(topologicalSort() == false){
        return -1;
    }
    fill(vl, vl+n, ve[n - 1]); // max
    while(!topOrder.empty()){
        int u = topOrder.top();
        topOrder.pop();
        for(int i = 0;i < G[u].size();i++){
            int v = G[u][i].v;
            if(vl[v] - G[u][i].w < vl[u]){
                vl[u] = vl[v] - G[u][i].w;
            }
        }
    }

    for(int u = 0;u < n;u++){
        for(int i = 0;i < G[u].size();i++){
            int v = G[u][i].v, w = G[u][i].w;
            int e = ve[u], l = vl[v] - w;
            if(e == l){
                // print u,v
            }
        }
    }
    return ve[n-1];
}
