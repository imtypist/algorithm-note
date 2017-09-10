#include <cstdio>

const int maxn = 51;
const int INF = 1000000000;
int d[maxn][maxn];

void floyd(int n){
    for(int k = 0;k < n;k++){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(d[i][k] + d[k][j] < d[i][j] && d[i][k] != INF && d[k][j] != INF){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            scanf("%d",&d[i][j]);
            if(i != j && d[i][j] == 0) d[i][j] = INF;
        }
    }
    floyd(n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(d[i][j] == INF) printf("-1 ");
            else printf("%d ",d[i][j]);
        }
        printf("\n");
    }
    return 0;
}
