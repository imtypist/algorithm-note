#include <cstdio>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 1000010;
int m,n;
int p[maxn];

int randPartition(int l, int r){
    int a = round(1.0*rand() / RAND_MAX *(r-l))+l;
    swap(p[l],p[a]);
    int temp = p[l];
    while(l < r){
        while(l < r && temp < p[r]) r--;
        p[l] = p[r];
        while(l < r && temp >= p[l]) l++;
        p[r] = p[l];
    }
    p[l] = temp;
    return l;
}

void randSelect(int l, int r, int k){
    if(l == r) return;
    int temp = randPartition(l,r);
    int s = temp - l + 1;
    if(s == k) return;
    if(s > k){
        randSelect(l,temp-1,k);
    }else{
        randSelect(temp+1,r,k-s);
    }
}

int main(){
    srand((unsigned)time(NULL));
    while(scanf("%d%d",&m,&n) != EOF){
        for(int i = 0;i < m;i++){
            scanf("%d",&p[i]);
        }
        randSelect(0,m-1,n+1);
        printf("%d\n",p[n]);
    }
}
