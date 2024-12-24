/**
 *    created: 24.12.2024_20:12:54
**/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/tmp/debug.h"
#else
#define debug(...) 42
#endif
void rec(int i, long long sum, long long target, vector<int>& a, bool& ok){
    if(i == (int)a.size()){
        if(sum == target){
            ok = true;
        }
        return;
    }
    rec(i + 1, sum + a[i], target, a,  ok);
    rec(i + 1, sum * a[i], target, a, ok);
    rec(i + 1, stoll(to_string(sum) + to_string(a[i])), target, a, ok);
}
int32_t main(){
    long long res;
    long long total_answer = 0;
    while(scanf("%lld: ", &res) != EOF){
        vector<int> v;
        while(true){
            int x;
            scanf("%d", &x);
            v.push_back(x);
            char c;
            scanf("%c", &c);
            if(c == ' '){
                continue;
            } else break;
        }
        bool ok = false;
        rec(1, v[0], res, v, ok);
        if(ok){
            total_answer += res;
        }
    }
    cout<<total_answer<<'\n';
    return 0;
}
