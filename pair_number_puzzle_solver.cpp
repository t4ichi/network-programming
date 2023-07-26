/*
2n 個のマスがあり、1つのマスには1つの数字がはいる。
数字は2個づつペアで入り、n個のマスを空けなければならない。
例
n=3 では
231213
312132

n=4では
23421314
41312432

が見つかる
では、 n=7 の場合
何個見つかるか求めなさい。
参考までに、 n=8 だと 300個 n=9 だと 0個
*/

#include <bits/stdc++.h>
using namespace std;

int n,N;
int ans = 0;
set<string> ans_set;

bool isFill(vector<int> p){
    for(int i = 0;i < p.size();i++){
        if(p[i] == -1) return false;
    }
    return true;
}

string vec2str(vector<int> p){
    string s = "";
    for(int i = 0;i < p.size();i++){
        s += p[i] + '1';
    }
    return s;
} 

void calc(vector<int> p,set<int> no_use,int idx,int num){
    if(num+idx+2 >= N) return;

    p[num+idx+2] = num;
    p[idx] = num;
    no_use.erase(num);

    if(no_use.size() == 0 && isFill(p)){
        ans++;
        ans_set.insert(vec2str(p));
    }

    for(auto i : no_use){
        for(int j = idx;j < N;j++){
            if(p[j] != -1) continue;
            calc(p,no_use,j,i);
        }
    }
}

int main(){
    cin >> n;
    N = n*2;
    vector<int> p(N,-1);
    set<int> no_use;    
    for (int i = 0; i < n; i++) {
        no_use.insert(i);
    }
    
    for(int i = 0;i < n;i++){
        calc(p,no_use,0,i);
    }

    for(auto v : ans_set){
        cout << v << "\n";
    }
    cout << ans << "\n";
}