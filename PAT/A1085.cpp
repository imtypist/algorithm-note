#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int a[maxn],p,n;;

int binarySearch(int i, long long x){
    if(a[n-1] <= x) return n;
    int left = i+1,right = n-1,mid;
    while(left < right){
        mid = (right+left)/2;
        if(a[mid] <= x){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    return left;
}

int main(){
    scanf("%d %d",&n,&p);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int ans = 1;
    for(int i=0;i<n;i++){
        int j = binarySearch(i, (long long)a[i]*p);
        ans = max(ans, j-i);
    }
    printf("%d\n",ans);
    return 0;
}
