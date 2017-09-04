#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 8;
char marix[maxn][maxn];
bool inq[maxn][maxn] = {false};
struct node{
    int x,y;
    int step;
}u,a,temp;
int x[] = {0,0,0,1,1,1,-1,-1,-1};
int y[] = {0,1,-1,0,1,-1,0,1,-1};

bool check(int x, int y, int step){
    if(x < 0 || x > 7 || y < 0 || y > 7) return false;
    if(inq[x][y]) return false;
    if(step > 7) return true;
    if(x >= step && marix[x-step][y] == 'S') return false;
    if(x >= (step + 1) && marix[x-step-1][y] == 'S') return false;
    return true;
}

bool BFS(node s){
    queue<node> q;
    s.step = 0;
    q.push(s);
    while(!q.empty()){
        node top = q.front();
        q.pop();
        if(top.x == a.x && top.y == a.y) return true;
        for(int i = 0;i < 9;i++){
            int newX = top.x + x[i];
            int newY = top.y + y[i];
            if(check(newX, newY, top.step)){
                temp.x = newX;
                temp.y = newY;
                temp.step = top.step + 1;
                inq[newX][newY] = true;
                q.push(temp);
            }
        }
    }
    return false;
}

int main(){
    int n;
    u.x = 7;u.y = 0;
    a.x = 0;a.y = 7;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 8;j++){
            for(int k = 0;k < 8;k++){
                scanf("%c",&marix[j][k]);
            }
            getchar();
        }
        getchar();
        bool flag = BFS(u);
        if(flag) printf("Case #%d: Yes\n",i+1);
        else printf("Case #%d: No\n",i+1);
    }
    return 0;
}
