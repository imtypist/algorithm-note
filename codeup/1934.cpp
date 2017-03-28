#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n,i,s;
    while(scanf("%d",&n) != EOF){
        int *p = (int*)malloc(sizeof(int)*n);
        memset(p,0,sizeof(int)*n);
        for(i = 0;i < n;i++){
            scanf("%d",&p[i]);
        }
        scanf("%d",&s);
        for(i = 0;i < n;i++){
            if(p[i] == s){
                printf("%d\n",i);
                break;
            }
        }
        if(i == n){
            printf("-1\n");
        }
        free(p);
    }
    return 0;
}
