#include <cstdio>
#include <math.h>
const int maxn = 21;
int n,k,sum = 0,count = 0;
bool p[maxn] = {false};
int a[maxn];

bool isPrime(int a){
    if(a <= 1) return false;
    int sqr = (int)sqrt(a*1.0);
    for(int i = 2;i <= sqr;i++){
        if(a % i == 0) return false;
    }
    return true;
}

void DFS(int nowK, int i){
    if(nowK == k){ // !!! not n
        if(isPrime(sum)){
            count++;
        }
        return;
    }
    for(i;i < n;i++){
        if((n - i) < (k - nowK)) return;
        if(p[i] == false){
            p[i] = true;
            sum += a[i];
            DFS(nowK + 1, i + 1);
            sum -= a[i];
            p[i] = false;
        }
    }
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    DFS(0, 0);
    printf("%d\n",count);
    return 0;
}
