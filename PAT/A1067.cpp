#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int num,ans=0;
    scanf("%d",&num);
    int arr[100010];
    int left=num-1;
    for(int i = 0;i<num;i++){
        scanf("%d",&arr[i]);
        if(arr[i] == i && i !=0){
            left--;
        }
    }
    int k=1;
    while(left>0){
        if(arr[0] == 0){
            for(int i=k;i<num;i++){
                if(arr[i]!=i){
                    swap(arr[0],arr[i]);
                    ans++;
                    break;
                }
                k++;
            }
        }
        while(arr[0]!=0){ //����0������ʵ�ֵ�ͬ����0��λ�ý���
            swap(arr[0],arr[arr[0]]);
            ans++;
            left--;
        }
    }
    printf("%d\n",ans);
    return 0;
}
