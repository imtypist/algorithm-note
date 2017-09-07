// Union Find Set
#include <cstdio>
const int N = 110;
int father[N];
bool isRoot[N] = {false};
int findFather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }
    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b){
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa != fb){
        father[fa] = fb;
    }
}

int main(){
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        father[i] = i;
    }
    for(int i = 0;i < m;i++){
        scanf("%d%d",&a,&b);
        Union(a,b);
    }
    for(int i = 1;i <= n;i++){
        isRoot[findFather(i)] = true;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        ans += isRoot[i];
    }
    printf("%d\n",ans);
    return 0;
}
