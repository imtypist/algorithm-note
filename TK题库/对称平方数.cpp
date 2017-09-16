#include <cstdio>

int num[10];

int main(){
    int n;
    for(int i = 0;i < 256;i++){
        n = i*i;
        int index = 0;
        while(n){
            num[index++] = n%10;
            n /= 10;
        }
        bool flag = true;
        for(int j = 0;j <= index/2;j++){
            if(num[j] != num[index-j-1]){
                flag = false;
                break;
            }
        }
        if(flag){
            printf("%d\n",i);
        }
    }
    return 0;
}
