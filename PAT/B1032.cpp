#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n,i;
    int score,num;
    scanf("%d",&n);
    int* p = (int*)malloc(sizeof(int)*(n+1));
    memset(p,0,sizeof(int)*(n+1));
    for(i = 0;i < n;i++){
        scanf("%d%d",&num,&score);
        p[num] += score;
    }
    int MAX = -1;
    for(i = 1;i <= n;i++){
        if(p[i] > MAX){
            MAX = p[i];
            num = i;
        }
    }
    printf("%d %d",num,MAX);
    return 0;
}
