#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 32;
int fn[maxn];

int F(int n){
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else{
        if(fn[n] == -1){
            int temp = F(n-1) + F(n-2);
            fn[n] = temp;
        }
        return fn[n];
    }
}

int main(){
    int n;
    scanf("%d",&n);
    fill(fn, fn+maxn, -1);
    int s = F(n);
    printf("%d\n",s);
    return 0;
}
