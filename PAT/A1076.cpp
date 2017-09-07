#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
const int maxn = 1010;
struct node{
    int data,layer;
};
vector<int> users[maxn];
bool vis[maxn];
int N,L;

int BFS(int root){
    queue<node> q;
    int sum = 0;
    node s;
    s.data = root;
    s.layer = 0;
    q.push(s);
    vis[root] = true;
    while(!q.empty()){
        node top = q.front();
        q.pop();
        node temp;
        for(int i = 0;i < users[top.data].size();i++){
            temp.data = users[top.data][i];
            temp.layer = top.layer + 1;
            if(vis[temp.data] == false && temp.layer <= L){
                vis[temp.data] = true;
                q.push(temp);
                sum++;
            }
        }
    }
    return sum;
}

int main(){
    scanf("%d%d",&N,&L);
    for(int i = 1;i <= N;i++){
        int num,data;
        scanf("%d",&num);
        for(int j = 0;j < num;j++){
            scanf("%d",&data);
            users[data].push_back(i);
        }
    }
    int qNum,temp,result;
    scanf("%d",&qNum);
    for(int i = 0;i < qNum;i++){
        scanf("%d",&temp);
        memset(vis, false, sizeof(vis));
        result = BFS(temp);
        printf("%d\n",result);
    }
    return 0;
}
