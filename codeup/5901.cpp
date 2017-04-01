#include <cstdio>
#include <string.h>

int main(){
    char a[255];
    gets(a);
    int len = strlen(a);
    bool flag = true;
    for(int i = 0;i < len / 2;i++){
        if(a[i] != a[len-i-1]){
            flag = false;
            printf("NO\n");
            break;
        }
    }
    if(flag) printf("YES\n");
    return 0;
}
