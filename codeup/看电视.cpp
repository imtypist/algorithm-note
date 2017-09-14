#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 110;

struct tv{
    int st,ed;
}shows[maxn];

bool cmp(tv a, tv b){
    if(a.st != b.st) return a.st > b.st;
    else return a.ed < b.ed;
}

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        if(n == 0) break;
        for(int i = 0;i < n;i++){
            scanf("%d%d",&shows[i].st,&shows[i].ed);
        }
        sort(shows, shows+n, cmp);
        int ans = 1,x = shows[0].st;
        for(int i = 1;i < n;i++){
            if(shows[i].ed <= x){
                x = shows[i].st;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
