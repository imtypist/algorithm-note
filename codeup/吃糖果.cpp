#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 25;
int f[maxn];

int main(){
    int n;
    memset(f, 0, sizeof(f));
    f[1] = 1;
    f[2] = 2;
    f[3] = 3;
    for(int i = 4;i <= 20;i++){
        f[i] = f[i-1] + f[i-2];
    }
    while(scanf("%d",&n) != EOF){
        printf("%d\n",f[n]);
    }
    return 0;
}
