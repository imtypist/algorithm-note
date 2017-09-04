#include <cstdio>
#include <algorithm>
const int maxn = 11;
bool p[maxn] = {false};
int a[maxn];
int n,count = 0;

void DFS(int index){
    if(index > n){
        for(int j = 1;j <=n;j++){
            printf("%d",a[j]);
            if(j != n) printf(" ");
            else printf("\n");
        }
        count++;
        return;
    }
    for(int i = 1;i <= n;i++){
        if(p[i] == false){
            bool flag = true;
            for(int pre = 1;pre < index;pre++){
                if(abs(pre - index) == abs(a[pre] - i)){
                    flag = false;
                    break;
                }
            }
            if(flag){
                p[i] = true;
                a[index] = i;
                DFS(index + 1);
                p[i] = false;
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    DFS(1);
    if(count == 0) printf("no solute!\n");
    return 0;
}
