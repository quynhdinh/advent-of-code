#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/tmp/debug.h"
#else
#define debug(...) 42
#endif
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int main(){
    vector<string> grid;
    while(true){
        string line;
        getline(cin, line);
        if(empty(line))
            break;
        grid.push_back(line);
    }
    int R = size(grid), C = size(grid[0]);
    auto inside = [&](int r, int c){
        return r >= 0 && r < R && c >= 0 && c < C;
    };
    pair<int, int> start, end;
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            if(grid[r][c] == 'S'){
                start = {r, c};
                grid[r][c] = '.';
            } else if(grid[r][c] == 'E'){
                end = {r, c};
                grid[r][c] = '.';
            }
        }
    }
    auto bfs = [&](pair<int, int> st) -> vector<vector<int>> {
        vector<vector<int>> D(R, vector<int>(C, -1));
        D[st.first][st.second] = 0;
        vector<pair<int, int>> q({st});
        for(int z = 0; z < (int)q.size(); z++){
            auto [r, c] = q[z];
            if(grid[r][c] == '#')
                continue;
            for(int dir = 0; dir < 4; dir++){
                int r2 = dx[dir] + r;
                int c2 = dy[dir] + c;
                if(inside(r2, c2) && D[r2][c2] == -1){
                    q.emplace_back(r2, c2);
                    D[r2][c2] = D[r][c] + 1;
                }
            }
        }
        return D;
    };
    vector<vector<int>> A = bfs(start), B = bfs(end);
    int normal = A[end.first][end.second];
    assert(normal == B[start.first][start.second]);
    int res = 0;
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            if(grid[r][c] == '#'){
                for(int dir = 0; dir < 4; dir++){
                    int r2 = dx[dir] + r;
                    int c2 = dy[dir] + c;
                    if(inside(r2, c2) && grid[r2][c2] != '#'){
                        int here = A[r][c] + B[r2][c2] + 1;
                        if(here <= normal - 100){
                            res++;
                        }
                    }
                }
            }
        }
    }
    cout<<res<<'\n';
}