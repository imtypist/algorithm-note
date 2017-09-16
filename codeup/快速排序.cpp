#include <cstdio>
#include <time.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int maxn = 5010;
int s[maxn];

int randPartition(int l, int r){
    int p = round(1.0*rand() / RAND_MAX * (r - l) + l);
    swap(s[p],s[l]);
    int temp = s[l];
    while(l < r){
        while(l < r && s[r] > temp) r--;
        s[l] = s[r];
        while(l < r && s[l] <= temp) l++;
        s[r] = s[l];
    }
    s[l] = temp;
    return l;
}

void qSort(int l, int r){
    if(l < r){
        int pos = randPartition(l,r);
        qSort(l,pos);
        qSort(pos+1,r);
    }
}

int main(){
    int n;
    srand((unsigned)time(NULL));
    while(scanf("%d",&n) != EOF){
        for(int i = 0;i < n;i++){
            scanf("%d",&s[i]);
        }
        qSort(0,n-1);
        for(int i = 0;i < n;i++){
            printf("%d\n",s[i]);
        }
    }
    return 0;
}
