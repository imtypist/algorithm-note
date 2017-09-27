#include <cstdio>

int main(){
    int a,b,c;
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            for(int k = 1;k < 10;k += 5){
                int carry = k*2/10;
                if(carry == 0){
                    if((j+k)%10 == 3){
                        carry = (j+k)/10;
                        if(i+j+carry == 5){
                            printf("%d %d %d\n",i,j,k);
                        }
                    }
                }else{
                    if((j+k)%10 == 2){
                        carry = (j+k)/10;
                        if(i+j+carry == 5){
                            printf("%d %d %d\n",i,j,k);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
