#include <iostream>
#include <string>
#include <string.h>
using namespace std;
const int maxn = 5010;
int indexn[maxn];
int dp[maxn][maxn];

bool isAlpha(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        return true;
    }else{
        return false;
    }
}

bool isDigit(char c){
    if(c >= '0' && c <= '9'){
        return true;
    }else{
        return false;
    }
}

char toUpperCase(char c){
    if(c >= 'A' && c <= 'Z'){
        return c;
    }else{
        return (c - 'a' + 'A');
    }
}

int main(){
    string origin,str;
    getline(cin, origin);
    for(int i = 0;i < origin.size();i++){
        char c = origin[i];
        int len = str.size();
        if(isAlpha(c)){
            str += toUpperCase(c);
            indexn[len] = i;
        }else if(isDigit(c)){
            str += c;
            indexn[len] = i;
        }
    }
    memset(dp, 0, sizeof(dp));
    int st,ans = 1,length = str.size();
    for(int i = 0;i < length;i++){
        dp[i][i] = 1;
        if(i < length - 1){
            if(str[i] == str[i+1]){
                if(ans < 2){
                    ans = 2;
                    st = 1;
                }
                dp[i][i+1] = 1;
            }
        }
    }
    for(int L = 3;L <= length;L++){
        for(int i = 0;i + L -1 < length;i++){
            if(str[i] == str[i+L-1] && dp[i+1][i+L-2] == 1){
                if(ans < L){
                    ans = L;
                    st = i;
                }
                dp[i][i+L-1] = 1;
            }
        }
    }
    for(int i = indexn[st];i <= indexn[st+ans-1];i++){
        cout << origin[i];
    }
    cout << endl;
    return 0;
}
