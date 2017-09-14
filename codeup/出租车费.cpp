#include <cstdio>

int main(){
    int n;
    double price;
    while(scanf("%d",&n) != EOF){
        if(n == 0) break;
        if(n <= 4){
            price = 10;
        }else if(n > 4 && n <= 8){
            price = 10 + (n-4)*2;
        }else{
            int s = n / 8;
            int r = n % 8;
            if(r >= 5){
                price = s * 18 + 10 + (r-4)*2;
            }else{
                price = s * 18 + r * 2.4;
            }
        }
        if(price - (int)price == 0){
            printf("%d\n",(int)price);
        }else{
            printf("%.1lf\n",price);
        }
    }
    return 0;
}
