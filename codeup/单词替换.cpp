#include <iostream>
#include <string>
using namespace std;

int main(){
    string str1,str2,str3;
    while(getline(cin, str1)){
        getline(cin, str2);
        getline(cin, str3);
        int lop = str1.size();
        int len = str2.size();
        int pos;
        bool ind[110] = {false};
        for(int i = 0;i < lop - len + 1;i++){
            if(str1[i] == str2[0]){
                if(str1.substr(i, len) == str2){
                    ind[i] = true;
                }
            }
        }
        for(int i = 0;i < lop - len + 1;i++){
            if(ind[i]){
                str1.replace(i, len, str3);
            }
        }
        cout << str1 << endl;
    }
    return 0;
}
