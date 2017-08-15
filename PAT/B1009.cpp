#include <stdio.h>
int main(){
    char ans[81][81];
    int i = 0;
    while(scanf("%s",ans[i]) != EOF){
        i++;
    }
    for(int j = (i-1);j >= 0;j--){
        printf("%s",ans[j]);
        if(j > 0) printf(" ");
    }
    return 0;
}
