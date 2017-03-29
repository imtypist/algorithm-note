#include <cstdio>

bool isLeap(int f){
    return (f % 400 == 0 || (f % 4 == 0 && f % 100 != 0));
}

int main(){
    int f,s,result;
    int fday,sday,fmonth,smonth;
    int month[13][2] = {{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
    while(scanf("%d%d",&f,&s) != EOF){
        result = 1;
        if(f < s){ // let f be the big number
            int temp = f;
            f = s;
            s = temp;
        }
        fday = f % 100;
        f /= 100;
        sday = s % 100;
        s /= 100;
        if(f == s){
            printf("%d\n",fday - sday + 1);
        }else{
            fmonth = f % 100;
            f /= 100;
            smonth = s % 100;
            s /= 100;
            if(f == s){
                if(isLeap(f)){
                    for(int i = smonth;i < fmonth;i++){
                        result += month[i][1];
                    }
                }else{
                    for(int i = smonth;i < fmonth;i++){
                        result += month[i][0];
                    }
                }
                result += fday - sday;
                printf("%d\n",result);
            }else{
                // good method
                while(!(f == s && fday == sday && fmonth == smonth)){
                    sday++;
                    if(sday == month[smonth][isLeap(s)] + 1){
                        sday = 1;
                        smonth++;
                        if(smonth == 13){
                            smonth = 1;
                            s++;
                        }
                    }
                    result++;
                }
                printf("%d\n",result);
            }
        }
    }
    return 0;
}
