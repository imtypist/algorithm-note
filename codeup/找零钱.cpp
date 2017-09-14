#include <cstdio>
#include <cstring>
using namespace std;
int money[5];
int p[] = {50,20,10,5,1};

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        memset(money, 0, sizeof(money));
        int kind = 0;
        while(n != 0){
            int temp;
            if(n >= 50){
                temp = n / 50;
                n = n % 50;
                money[0] = temp;
                kind++;
            }else if(n >= 20 && n < 50){
                temp = n / 20;
                n = n % 20;
                money[1] = temp;
                kind++;
            }else if(n >= 10 && n < 20){
                temp = n / 10;
                n = n % 10;
                money[2] = temp;
                kind++;
            }else if(n >= 5 && n < 10){
                temp = n / 5;
                n = n % 5;
                money[3] = temp;
                kind++;
            }else{
                temp = n / 1;
                n = n % 1;
                money[4] = temp;
                kind++;
            }
        }
        for(int i = 0;i < 5;i++){
            if(money[i] > 0){
                printf("%d*%d",p[i],money[i]);
                if((--kind) > 0) printf("+");
            }
        }
        printf("\n");
    }
    return 0;
}
