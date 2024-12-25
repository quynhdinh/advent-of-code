#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    vector<int> x, y;
    while(cin>>a>>b){
        x.push_back(a);
        y.push_back(b);
    }
    sort(begin(x), end(x));
    sort(begin(y), end(y));
    int res = 0;
    for(int i = 0; i < (int)size(x); i++)
        res += abs(x[i] - y[i]);
    cout<<res<<'\n';
    return 0;
}