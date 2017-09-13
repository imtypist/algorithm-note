#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct stu{
    int stuNo;
    char name[10];
    int score;
};
const int maxn = 100010;

stu s[maxn];

bool cmpNo(stu a, stu b){
    return a.stuNo < b.stuNo;
}

bool cmpName(stu a, stu b){
    int s = strcmp(a.name,b.name);
    if(s != 0){
        if(s < 0){
            return true;
        }else{
            return false;
        }
    }
    else return a.stuNo < b.stuNo;
}

bool cmpScore(stu a, stu b){
    if(a.score != b.score) return a.score < b.score;
    else return a.stuNo < b.stuNo;
}

int main(){
    int n,c;
    while(scanf("%d%d",&n,&c) != EOF){
        if(n == 0) break;
        for(int i = 0;i < n;i++){
            scanf("%d %s %d",&s[i].stuNo,s[i].name,&s[i].score);
        }
        if(c == 1){
            sort(s, s+n, cmpNo);
        }else if(c == 2){
            sort(s, s+n, cmpName);
        }else{
            sort(s, s+n, cmpScore);
        }
        printf("Case %d:\n",c);
        for(int i = 0;i < n;i++){
            printf("%06d %s %d\n",s[i].stuNo,s[i].name,s[i].score);
        }
    }
    return 0;
}
