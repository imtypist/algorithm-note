#include <cstdio>
const int maxn = 1000001;
int p[maxn], pnum = 0;
bool prime[maxn] = {0};
void Find_Prime(int n){
    for(int i = 2;i < maxn;i++){
        if(prime[i] == false){
            p[pnum++] = i;
            if(pnum >= n) break;
            for(int j = i + i;j < maxn;j += i){
                prime[j] = true;
            }
        }
    }
}

int main(){
    int m,n,count = 0;
    scanf("%d%d",&m,&n);
    Find_Prime(n);
    for(int i = m;i <=n;i++){
        printf("%d",p[i-1]);
        count++;
        if(count % 10 != 0 && i < n) printf(" ");
        else printf("\n");
    }
    return 0;
}
