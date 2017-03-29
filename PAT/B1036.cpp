#include <stdio.h>

int main(){
    int n,row;
    char c;
    scanf("%d %c",&n,&c);
    if(n % 2 == 0){
        row = n / 2;
    }else{
        row = n / 2 + 1;
    }
    for(int i = 0;i < n;i++){
        printf("%c",c);
    }
    printf("\n");
    for(int j = 0;j < (row - 2);j++){
        for(int i = 0;i < n;i++){
            if(i != 0 && i != (n - 1)){
                printf(" ");
            }else if(i == 0){
                printf("%c",c);
            }else{
                printf("%c\n",c);
            }
        }
    }
    for(int i = 0;i < n;i++){
        printf("%c",c);
    }
    return 0;
}
