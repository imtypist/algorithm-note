#include <cstdio>

const int maxn = 25;
int n,num;
int p[maxn];

void generateP(int index, int sum){
    if(index == n + 1){
        if(sum == 40) num++;
        return;
    }
    if(sum == 40){
        num++;
        return;
    }
    if(sum > 40) return;
    generateP(index + 1, sum);
    generateP(index + 1, sum + p[index]);
}


int main(){
    while(scanf("%d",&n) != EOF){
        for(int i = 1;i <= n;i++){
            scanf("%d",&p[i]);
        }
        num = 0;
        generateP(1, 0);
        printf("%d\n",num);
    }
    return 0;
}
