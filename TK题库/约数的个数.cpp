#include <cstdio>
#include <cstring>
#include <cmath>

int num[1010];

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        if(n == 0) break;
        for(int i = 0;i < n;i++){
            scanf("%d",&num[i]);
        }
        for(int i = 0;i < n;i++){
            int sum = 2;
            int sqr = (int)sqrt(1.0*num[i]);
            for(int j = 2;j <= sqr;j++){
                if(num[i] % j == 0){
                    sum += 2;
                }
            }
            if(sqr*sqr == num[i]){
                sum--;
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
