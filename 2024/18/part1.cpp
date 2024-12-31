#include <bits/stdc++.h>
using namespace std;

const int S = 71;
const int INF = 1e9 + 5;

vector<string> get_strings(string str){
    vector<string> internal;
    stringstream ss(str);
    char delimiter = ',';
    string tok;
    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }
    return internal;
}
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int32_t main(){
    vector<vector<bool>> vis(S, vector<bool>(S, false));
    vector<vector<int>> d(S, vector<int>(S, INF));
    for(int i = 0; i < 1024; i++){
        string line;
        getline(cin, line);
        if(empty(line)){
            break;
        }
        auto strings = get_strings(line);
        int x = stoi(strings[0]);
        int y = stoi(strings[1]);
        assert(x >= 0 && y >= 0);
        vis[x][y] = true;
    }
    assert(!vis[0][0]);
    vis[0][0] = true;
    d[0][0] = 0;
    queue<pair<int, int>> q({{0, 0}});
    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int r2 = dx[dir] + r;
            int c2 = dy[dir] + c;
            if(min(r2, c2) >= 0 && max(r2, c2) < S && !vis[r2][c2]){
                d[r2][c2] = d[r][c] + 1;
                vis[r2][c2] = true;
                q.push({r2, c2});
            }
        }
    }
    cout<<d[S - 1][S - 1]<<'\n';
    return 0;
}