#include <cstdio>

int main(){
    int n;
    scanf("%d",&n);
    int* node = new int[n];
    int a,b,max;
    node[1] = max = 1;
    while(scanf("%d%d",&a,&b) != EOF){
        node[b] = node[a] + 1;
        if(node[b] > max){
            max = node[b];
        }
    }
    printf("%d\n",max);
    delete(node);
    return 0;
}
