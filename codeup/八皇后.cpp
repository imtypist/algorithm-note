#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100;
bool vis[maxn] = {false};
vector<int> q[maxn];
int sum = 1;
vector<int> temp;

void generateP(int ind){
    if(9 == ind){
        q[sum++] = temp;
        return;
    }
    for(int i = 1;i <= 8;i++){
        if(vis[i] == false){
            bool flag = true;
            for(int j = 1;j < ind;j++){
                if(abs(j-ind) == abs(i-temp[j-1])){
                    flag = false;
                    break;
                }
            }
            if(flag){
                temp.push_back(i);
                vis[i] = true;
                generateP(ind + 1);
                vis[i] = false;
                temp.pop_back();
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int d;
    generateP(1);
    for(int i = 0;i < n;i++){
        scanf("%d",&d);
        for(int j = 0;j < 8;j++){
            printf("%d",q[d][j]);
        }
        printf("\n");
    }
    return 0;
}
