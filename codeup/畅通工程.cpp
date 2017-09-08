#include <cstdio>
const int maxn = 1010;
int N,M;
int path[maxn];

int findFather(int a){
    int x = a;
    while(a != path[a]){
        a = path[a];
    }
    while(x != path[x]){
        int z = x;
        x = path[x];
        path[z] = a;
    }
    return a;
}

void merge(int a, int b){
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa != fb){
        path[fa] = fb;
    }
}

int main(){
    while(1){
        scanf("%d",&N);
        if(N == 0) break;
        scanf("%d",&M);
        int a,b;
        for(int i = 1;i <= N;i++) path[i] = i;
        for(int i = 0;i < M;i++){
            scanf("%d %d",&a,&b);
            merge(a ,b);
        }
        int count = 0;
        for(int i = 1;i <= N;i++){
            if(path[i] == i){
                count++;
            }
        }
        printf("%d\n",count-1);
    }
    return 0;
}
