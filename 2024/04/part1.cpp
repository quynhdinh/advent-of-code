/**
 *    created: 25.12.2024_14:30:51
**/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/tmp/debug.h"
#else
#define debug(...) 42
#endif

int32_t main(){
    vector<string> grid;
    while(true){
        string row;
        getline(cin, row);
        if(empty(row))
            break;
        grid.push_back(row);
    }
    int R = size(grid), C = size(grid[0]);
    int res = 0;
    for(int r = 0; r < R; r++){
        assert((int)size(grid[r]) == C);
        for(int c = 0; c < C; c++){
            if(grid[r][c] == 'X'){
                if(r + 3 < R){
                    if(grid[r + 1][c] == 'M' && grid[r + 2][c] == 'A' && grid[r + 3][c] == 'S'){
                        res++;
                    }
                }
                if(c + 3 < C){
                    if(grid[r][c + 1] == 'M' && grid[r][c + 2] == 'A' && grid[r][c + 3] == 'S'){
                        res++;
                    }
                }
                if(r - 3 >= 0){
                    if(grid[r - 1][c] == 'M' && grid[r - 2][c] == 'A' && grid[r - 3][c] == 'S'){
                        res++;

                    }
                }
                if(c - 3 >= 0){
                    if(grid[r][c - 1] == 'M' && grid[r][c - 2] == 'A' && grid[r][c - 3] == 'S'){
                        res++;
                    }
                }
                if(r + 3 < R && c + 3 < C){
                    if(grid[r + 1][c + 1] == 'M' && grid[r + 2][c + 2] == 'A' && grid[r + 3][c + 3] == 'S'){
                        res++;
                    }
                }
                if(r - 3 >= 0 && c - 3 >= 0){
                    if(grid[r - 1][c - 1] == 'M' && grid[r - 2][c - 2] == 'A' && grid[r - 3][c - 3] == 'S'){
                        res++;
                    }
                }
                if(r - 3 >= 0 && c + 3 < C){
                    if(grid[r - 1][c + 1] == 'M' && grid[r - 2][c + 2] == 'A' && grid[r - 3][c + 3] == 'S'){
                        res++;
                    }
                }
                if(r + 3 < R && c - 3 >= 0){
                    if(grid[r + 1][c - 1] == 'M' && grid[r + 2][c - 2] == 'A' && grid[r + 3][c - 3] == 'S'){
                        res++;
                    }
                }
            }
        }
    }
    cout<<res<<'\n';
    return 0;
}