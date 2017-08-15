#include <cstdio>

int main(){
    int n,m,temp;
    scanf("%d %d",&n,&m);
    int hashTable[1005] = {0};
    for(int i = 0;i < n;i++){
        scanf("%d",&temp);
        hashTable[temp]++;
    }
    for(int i = 0;i < 1005;i++){
        if(m - i < 0) break;
        if(hashTable[i] && hashTable[m-i]){
            if(i == m-i && hashTable[i] <= 1){
                continue;
            }
            printf("%d %d\n",i,m-i);
            return 0;
        }
    }
    printf("No Solution\n");
    return 0;
}
