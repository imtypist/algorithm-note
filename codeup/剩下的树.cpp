#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;

bool p[maxn];

int main(){
    int L,M;
    while(scanf("%d%d",&L,&M) != EOF){
        if(L == 0 && M == 0) break;
        fill(p,p+maxn,1);
        int st,ed;
        for(int i = 0;i < M;i++){
            scanf("%d%d",&st,&ed);
            for(int j = st;j <= ed;j++){
                p[j] = 0;
            }
        }
        int sum = 0;
        for(int i = 0;i <= L;i++){
            if(p[i]) sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
