#include <cstdio>

int main(){
    int a,b,d,i;
    int r[40] = {0};
    scanf("%d%d%d",&a,&b,&d);
    a = a + b;
    for(i = 0;i < 40;i++){
        if(a == 0){
            if(i > 0) i--;
            break;
        }
        r[i] = a % d;
        a /= d;
    }
    for(int j = i;j >= 0;j--){
        printf("%d",r[j]);
    }
    printf("\n");
    return 0;
}
