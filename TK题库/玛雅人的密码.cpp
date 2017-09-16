#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int cnt[3];
map<string ,int> mp;

bool isOk(string str){
    int len = str.size();
    for(int i = 0;i < len-3;i++){
        if(str[i] == '2' && str[i+1] == '0' && str[i+2] == '1' && str[i+3] == '2'){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    string str;
    queue<pair<string,int> > q;
    while(cin >> n){
        cin >> str;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0;i < n;i++){
            cnt[str[i] - '0']++;
        }
        if(cnt[0] < 1 || cnt[1] < 1 || cnt[2] < 2){
            cout << -1 << endl;
            continue;
        }
        mp.clear();
        while(!q.empty()){
            q.pop();
        }
        mp[str] = 1;
        q.push(make_pair(str,0));
        int ans = -1;
        while(!q.empty()){
            pair<string,int> p = q.front();
            q.pop();
            string t = p.first;
            int st = p.second;
            if(isOk(t)){
                ans = st;
                break;
            }
            for(int i = 0;i+1 < n;i++){
                string temp = t;
                swap(temp[i],temp[i+1]);
                if(mp.find(temp) == mp.end()){
                    mp[temp] = 1;
                    q.push(make_pair(temp,st+1));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
