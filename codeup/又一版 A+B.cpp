#include <cstdio>

int main(){
    int m,num;
    long long a,b;
    int s[40];
    while(scanf("%d%lld%lld",&m,&a,&b) != 1){
        num = 0;
        long long c = a + b;
        do{
            s[num++] = c % m;
            c /= m;
        }while(c != 0);
        for(int i = num - 1;i >= 0;i--){
            printf("%d",s[i]);
        }
        printf("\n");
    }
    return 0;
}
