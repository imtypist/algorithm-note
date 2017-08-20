#include <cstdio>
#include <math.h>

bool isPrime(int a){
    int qrt = (int)sqrt(a*1.0);
    for(int i = 2;i <= qrt;i++){
        if(a % i == 0) return false;
    }
    return true;
}

struct factors{
    int num, cnt;
}fac[10];
int prime[100010],pNum = 0;

void findPrime(){
    for(int i = 2;i < 100010;i++){
        if(isPrime(i)){
            prime[pNum++] = i;
        }
    }
}

int main(){
    findPrime();
    int N;
    scanf("%d",&N);
    if(N == 1){
        printf("1=1\n");
    }else{
        printf("%d=",N);
        int sqr = (int)sqrt(1.0*N);
        int num = 0;
        for(int i = 0;i < pNum && prime[i] <= sqr;i++){
            if(N % prime[i] == 0){
                fac[num].num = prime[i];
                fac[num].cnt = 0;
                while(N % prime[i] == 0){
                    fac[num].cnt++;
                    N /= prime[i];
                }
                num++;
            }
            if(N == 1) break;
        }
        if(N != 1){
            fac[num].num = N;
            fac[num++].cnt = 1;
        }
        for(int i = 0;i < num;i++){
            if(i > 0) printf("*");
            printf("%d",fac[i].num);
            if(fac[i].cnt > 1){
                printf("^%d",fac[i].cnt);
            }
        }
        printf("\n");
    }
    return 0;
}
