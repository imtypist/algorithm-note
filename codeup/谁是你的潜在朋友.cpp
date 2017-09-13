#include <cstdio>
#include <cstring>
const int maxn = 210;
int books[maxn];
int p[maxn];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int temp;
    memset(books, 0, sizeof(books));
    for(int i = 0;i < n;i++){
        scanf("%d",&temp);
        p[i] = temp;
        books[temp]++;
    }
    for(int i = 0;i < n;i++){
        if(books[p[i]] <= 1){
            printf("BeiJu\n");
        }else{
            printf("%d\n",books[p[i]]-1);
        }
    }
    return 0;
}
