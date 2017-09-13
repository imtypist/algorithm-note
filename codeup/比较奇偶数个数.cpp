#include <cstdio>

int main(){
    int odd = 0,even = 0;
    int n;
    while(scanf("%d",&n) != EOF){
        int temp;
        for(int i = 0;i < n;i++){
            scanf("%d",&temp);
            if(temp & 1){
                odd++;
            }else{
                even++;
            }
        }
        if(even > odd) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
