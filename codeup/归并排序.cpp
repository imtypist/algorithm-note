// O(nlogn)
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;

void merge(int s[], int l1, int r1, int l2, int r2){
    int temp[maxn];
    int index = 0,i = l1,j = l2;
    while(i <= r1 && j <= r2){
        if(s[i] <= s[j]){
            temp[index++] = s[i++];
        }else{
            temp[index++] = s[j++];
        }
    }
    while(i <= r1) temp[index++] = s[i++];
    while(j <= r2) temp[index++] = s[j++];
    for(int i = 0;i < index;i++){
        s[l1+i] = temp[i];
    }
}

void mergeSort(int s[], int n){
    for(int step = 2;step/2 <= n;step *= 2){
        for(int i = 0;i < n;i += step){
            int mid = i + step / 2 -1;
            if(mid + 1 < n){
                merge(s,i,mid,mid+1,min(i+step-1,n-1));
            }
        }
    }
}

int main(){
    int n,m;
    int s[maxn];
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        for(int i = 0;i < m;i++){
            scanf("%d",&s[i]);
        }
        mergeSort(s, m);
        for(int i = 0;i < m;i++){
            printf("%d\n",s[i]);
        }
    }
    return 0;
}
