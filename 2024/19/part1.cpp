/**
 *    created: 30.12.2024_23:53:10
**/
#include <bits/stdc++.h>
using namespace std;

vector<string> get_strings(string str){
    vector<string> internal;
    stringstream ss(str);
    char delimiter = ' ';
    string tok;
    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }
    return internal;
}

int32_t main(){
    string line;
    getline(cin, line);
    vector<string> strings = get_strings(line);
    for(auto& str: strings){
        if(str.back() == ','){
            str.pop_back();
        }
    }
    getline(cin, line);
    assert(empty(line));
    int res = 0;
    while(true){
        getline(cin, line);
        int n = (int)size(line);
        if(n == 0){
            break;
        }
        vector<int> dp(n + 1);
        dp[0] = 1;
        for(int i = 0; i <= n; i++){
            if(dp[i]){
                for(auto str: strings){
                    int k = (int)size(str);
                    if(i + k <= n){
                        bool ok = true;
                        for(int j = 0; j < k; j++){
                            if(str[j] != line[j + i]){
                                ok = false;
                                break;
                            }
                        }
                        if(ok){
                            dp[i + k] = 1;
                        }
                    }
                }
            }
        }
        if(dp[n]){
            res++;
        }
    }
    cout<<res<<'\n';
    return 0;
}
