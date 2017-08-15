#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int nc,np;
    int ncs[100010],nps[100010];
    long long ans = 0;
    scanf("%d",&nc);
    for(int i = 0;i<nc;i++){
        scanf("%d",&ncs[i]);
    }
    scanf("%d",&np);
    for(int i = 0;i<np;i++){
        scanf("%d",&nps[i]);
    }
    sort(ncs,ncs+nc);
    sort(nps,nps+np);
    int i=0,j=0;
    while(i<nc && j<np && ncs[i] < 0 && nps[j] < 0){
        ans += ncs[i]*nps[j];
        i++;
        j++;
    }
    i = nc-1;
    j = np-1;
    while(i>=0 && j>=0 && ncs[i] > 0 && nps[j] > 0){
        ans += ncs[i]*nps[j];
        i--;
        j--;
    }
    printf("%d\n",ans);
    return 0;
}
