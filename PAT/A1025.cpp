#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student{
    char reg_id[15];
    int location_num;
    int score;
    int local_rank;
}stu[30010];
bool cmp(Student a, Student b){
    if(a.score != b.score) return (a.score > b.score);
    else return strcmp(a.reg_id, b.reg_id) < 0;
}
int main(){
    int location,num = 0;
    scanf("%d",&location);
    for(int i = 1;i <= location;i++){
        int k;
        scanf("%d",&k);
        for(int j = 0;j < k;j++){
            scanf("%s %d",stu[num].reg_id,&stu[num].score);
            stu[num].location_num = i;
            num++;
        }
        sort(stu+num-k,stu+num,cmp);
        stu[num-k].local_rank = 1;
        for(int m = num - k + 1;m < num;m++){
            if(stu[m].score == stu[m-1].score) stu[m].local_rank = stu[m-1].local_rank;
            else stu[m].local_rank = m - (num - k) + 1;
        }
    }
    printf("%d\n",num);
    sort(stu,stu+num,cmp);
    int prev = 1;
    printf("%s %d %d %d\n",stu[0].reg_id,prev,stu[0].location_num,stu[0].local_rank);
    for(int j = 1;j < num;j++){
        if(stu[j].score != stu[j-1].score){
            prev = j + 1;
        }
        printf("%s %d %d %d\n",stu[j].reg_id,prev,stu[j].location_num,stu[j].local_rank);
    }
    return 0;
}
