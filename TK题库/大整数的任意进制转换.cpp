#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool isAlpha(char a){
    if(a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z'){
        return true;
    }else{
        return false;
    }
}

int main(){
    int M,N;
    int data[1010],output[1010];
    string X;
    while(cin >> M >> N){
        cin >> X;
        memset(output, 0, sizeof(output));
        int len = X.size();
        for(int i = 0;i < len;i++){
            if(isAlpha(X[i])){
                data[i] = X[i] - 'A' + 10;
            }else{
                data[i] = X[i] - '0';
            }
        }
        int sum,d;
        int k = 0;
        while(sum){
            sum = 0;
            for(int i = 0;i < len;i++){
                d = data[i] / N;
                sum += d;
                if(i == len-1){
                    output[k++] = data[i] % N;
                }else{
                    data[i+1] += (data[i] % N) * M;
                }
                data[i] = d;
            }
        }
        if(k == 0){
            cout << 0 << endl;
        }else{
            for(int j = 0;j < k;j++){
                if(output[k-j-1] > 9){
                    cout << (char)(output[k-j-1] + 'a' - 10);
                }else{
                    cout << output[k-j-1];
                }
            }
            cout << endl;
        }
    }
    return 0;
}
