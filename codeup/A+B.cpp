#include <cstdio>
#include <string.h>
const int maxn = 20;

struct bign{
    int d[maxn];
    int len;
    bool isNeg;
    bign(){
        memset(d, 0 ,sizeof(d));
        len = 0;
        isNeg = false;
    }
};

bign change(char c[]){
    bign a;
    for(int i = strlen(c) - 1;i >= 0;i--){
        if(c[i] == ',') continue;
        else if(c[i] == '-') a.isNeg = true;
        else{
            a.d[a.len++] = c[i] - '0';
        }
    }
    return a;
}

int compare(bign a,bign b){
    if(a.len > b.len) return true;
    else if(a.len < b.len) return false;
    else{
        for(int i = a.len - 1;i >= 0;i--){
            if(a.d[i] > b.d[i]) return true;
            else if(a.d[i] < b.d[i]) return false;
        }
    }
    return -1;
}

bign add(bign a, bign b){
    bign c;
    int carry = 0;
    for(int i = 0;i < a.len || i< b.len;i++){
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if(carry != 0){
        c.d[c.len++] = carry;
    }
    return c;
}

bign sub(bign a, bign b){
    bign c;
    for(int i = 0;i < a.len || i < b.len;i++){
        if(a.d[i] < b.d[i]){
            a.d[i + 1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while(c.len - 1 >= 1 && c.d[c.len - 1] == 0){
        c.len--;
    }
    return c;
}

int main(){
    char c1[maxn],c2[maxn];
    while(scanf("%s %s",c1,c2) != EOF){
        bign a = change(c1);
        bign b = change(c2);
        bign c;
        int s = compare(a,b);
        if((a.isNeg == false && b.isNeg == false) || (a.isNeg == true && b.isNeg == true)){
            c = add(a,b);
            if(a.isNeg == true){
                printf("-");
            }
        }else if(a.isNeg == true && b.isNeg == false){
            if(s == 1){
                c = sub(a,b);
                printf("-");
            }else{
                c = sub(b,a);
            }
        }else{
            if(s == 1){
                c = sub(a,b);
            }else{
                c = sub(b,a);
                printf("-");
            }
        }
        for(int i = c.len-1;i >= 0;i--){
            printf("%d",c.d[i]);
        }
        printf("\n");
    }
    return 0;
}
