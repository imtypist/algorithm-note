#include <cstdio>

int month[13][2] = {{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};

bool isLeapYear(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main(){
    int y1,y2;
    while(scanf("%d%d",&y1,&y2) != EOF){
        int rs = 1;
        if(y1 != y2){
            if(y1 < y2){
                int temp = y1;
                y1 = y2;
                y2 = temp;
            }
            int m1,d1;
            int m2,d2;
            d1 = y1 % 100;
            y1 /= 100;
            m1 = y1 % 100;
            y1 /= 100;
            d2 = y2 % 100;
            y2 /= 100;
            m2 = y2 % 100;
            y2 /= 100;
            while(y1 > y2 || m1 > m2 || d1 > d2){
                d2++;
                if(d2 > month[m2][isLeapYear(y2)]){
                    m2++;
                    d2 = 1;
                }
                if(m2 > 12){
                    m2 = 1;
                    y2++;
                }
                rs++;
            }
        }
        printf("%d\n",rs);
    }
    return 0;
}
