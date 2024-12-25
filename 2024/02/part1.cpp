/**
 *    created: 25.12.2024_14:11:56
**/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/tmp/debug.h"
#else
#define debug(...) 42
#endif
vector<int> get_strings(string str){
    vector<int> internal;
    stringstream ss(str);
    char delimiter = ' ';
    string tok;
    while(getline(ss, tok, delimiter)) {
        internal.push_back(stoi(tok));
    }
    return internal;
}
int main(){
    int res = 0;
    int cnt = 1;
    while(true){
        string line;
        getline(cin, line);
        if(empty(line))
            break;
        vector<int> arr = get_strings(line);
        bool diff = true, increasing = true, decreasing = true;
        for(int i = 0; i < (int)size(arr) - 1; i++){
            if(!(abs(arr[i] - arr[i + 1]) >= 1 && abs(arr[i] - arr[i + 1]) <= 3))
                diff = false;
            if(arr[i] > arr[i + 1]){
                increasing = false;
            } else if(arr[i] < arr[i + 1]){
                decreasing = false;
            }
        }
        if(diff && (increasing || decreasing))
            res++;
        cnt++;
    }
    cout<<res<<'\n';
    return 0;
}