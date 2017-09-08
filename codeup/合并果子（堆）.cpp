#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 30000;
priority_queue<int, vector<int>, greater<int> > q;

int main(){
    int n;
    scanf("%d",&n);
    int data;
    for(int i = 1;i <= n;i++){
        scanf("%d",&data);
        q.push(data);
    }
    int weight = 0,temp;
    while(!q.empty()){
        int q1 = q.top();
        q.pop();
        int q2 = q.top();
        q.pop();
        temp = q1 + q2;
        weight += temp;
        if(q.size() == 0) break;
        q.push(temp);
    }
    printf("%d\n",weight);
    return 0;
}
