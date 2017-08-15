#include <cstdio>
#include <algorithm>
using namespace std;

struct station{
    double price;
    double dist;
}stations[500];

bool cmp(station a,station b){
    if(a.dist != b.dist) return a.dist < b.dist;
    else return a.price < b.price;
}

int main(){
    double cmax,d,davg,total_price = 0,per_dist;
    int n;
    scanf("%lf %lf %lf %d",&cmax,&d,&davg,&n);
    per_dist = cmax * davg;
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&stations[i].price,&stations[i].dist);
    }
    sort(stations,stations+n,cmp);
    stations[n].price = 0;
    stations[n].dist = d;
    if(stations[0].dist != 0){
        printf("The maximum travel distance = 0.00\n");
    }else{
        double nowTank = 0;
        int now = 0;
        while(now < n){
            int k = -1;
            double priceMin = 1000000000;
            for(int i = now+1;i<=n && stations[i].dist - stations[now].dist <= per_dist;i++){
                if(stations[i].price < priceMin){
                    priceMin = stations[i].price;
                    k = i;
                    if(priceMin < stations[now].price){
                        break;
                    }
                }
            }
            if(k==-1) break;
            double need = (stations[k].dist - stations[now].dist) / davg;
            if(priceMin < stations[now].price){
                if(nowTank < need){
                    total_price += stations[now].price*(need - nowTank);
                    nowTank=0;
                }else{
                    nowTank -= need;
                }
            }else{
                total_price += stations[now].price*(cmax-nowTank);
                nowTank = cmax - need;
            }
            now = k;
        }
        if(now == n){
            printf("%.2f\n",total_price);
        }else{
            printf("The maximum travel distance = %.2f\n",stations[now].dist+per_dist);
        }
    }
    return 0;
}
