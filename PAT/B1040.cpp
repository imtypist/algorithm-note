#include <cstdio>
#include <cstring>
const int maxn = 100010;
const int MOD = 1000000007;

int main(){
    int leftP[maxn] = {0};
    char str[maxn];
    gets(str);
    int len = strlen(str);
    for(int i = 0;i < len;i++){
        if(i > 0){
            leftP[i] = leftP[i-1];
        }
        if(str[i] == 'P'){
            leftP[i]++;
        }
    }
    int rightT = 0, ans = 0;
    for(int i = len-1;i >= 0;i--){
        if(str[i] == 'T') rightT++;
        else if(str[i] == 'A'){
            ans = (ans + leftP[i] * rightT) % MOD;
        }
    }
    printf("%d\n",ans);
    return 0;
}
