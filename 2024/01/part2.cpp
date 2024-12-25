#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    vector<int> x;
    map<int, int> cnt;
    while(cin>>a>>b){
        x.push_back(a);
        cnt[b]++;
    }
    int res = 0;
    for(int i = 0; i < (int)size(x); i++)
        res += cnt[x[i]] * x[i];
    cout<<res<<'\n';
    return 0;
}