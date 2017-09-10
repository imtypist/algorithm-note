#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        int data;
        while(!q.empty()) q.pop();
        for(int i = 0;i < n;i++){
            scanf("%d",&data);
            q.push(data);
        }
        int weight = 0;
        while(q.size() >1){
            int q1 = q.top();
            q.pop();
            int q2 = q.top();
            q.pop();
            int temp = q1 + q2;
            weight += temp;
            q.push(temp);
        }
        printf("%d\n",weight);
    }
    return 0;
}
