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
struct DSU {
	vector<int> e; void init(int N) { e = vector<int>(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int32_t main(){
    vector<vector<bool>> vis(S, vector<bool>(S, false));
    vector<vector<int>> d(S, vector<int>(S, INF));
    vector<pair<int, int>> cells;
    while(true){
        string line;
        getline(cin, line);
        if(empty(line)){
            break;
        }
        auto strings = get_strings(line);
        int x = stoi(strings[0]);
        int y = stoi(strings[1]);
        cells.push_back({x, y});
    }
    auto inside = [&](int r, int c){
        return min(r, c) >= 0 && max(r, c) < S;
    };
    auto Bfs = [&]() -> bool{
        vector<vector<bool>> v = vis;
        queue<pair<int, int>> q({{0, 0}});
        v[0][0] = true;
        while(!empty(q)){
            auto [r, c] = q.front();
            q.pop();
            for(int dir = 0; dir < 4; dir++){
                int r2 = dx[dir] + r;
                int c2 = dy[dir] + c;
                if(inside(r2, c2) && !v[r2][c2]){
                    v[r2][c2] = true;
                    q.push({r2, c2});
                }
            }
        }
        return v[S - 1][S - 1];
    };
    for(auto& [r, c]: cells){
        vis[r][c] = true;
        if(!Bfs()){
            cout<<r<<','<<c<<'\n';
            return 0;
        }
    }
    return 0;
}
/*
This is a slow solution: for every blocked cell run a dfs from start to ending cell
Better solution: binary search the answer, for every blocked cell, store its index
Great solution: Remove every blocked cell from the end, main tain a DSU to quick
check the connectivity from start to end cell
*/