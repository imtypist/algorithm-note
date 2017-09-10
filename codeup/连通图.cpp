#include <cstdio>
const int maxn = 1010;
int p[maxn];

int findFather(int x){
    int a = x;
    while(x != p[x]){
        x = p[x];
    }
    while(a != p[a]){
        int z = a;
        a = p[a];
        p[z] = x;
    }
    return x;
}

void merge(int a, int b){
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa != fb){
        p[fa] = fb;
    }
}

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)){
        if(n == 0) break;
        for(int i = 1;i <= n;i++) p[i] = i;
        int a,b;
        for(int i = 0;i < m;i++){
            scanf("%d%d",&a,&b);
            merge(a,b);
        }
        int count = 0;
        for(int i = 1;i <= n;i++){
            if(p[i] == i) count++;
        }
        if(count == 1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
