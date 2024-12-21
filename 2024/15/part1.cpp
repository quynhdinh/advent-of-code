#include <bits/stdc++.h>
using namespace std;

pair<int, int> getDir(char c){
    if(c == '<'){
        return {0, -1};
    } else if(c == '>'){
        return {0, 1};
    } else if(c == '^'){
        return {-1, 0};
    } else if(c == 'v'){
        return {1, 0};
    }
    assert(false);
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<string> grid;
    string line;
    while (getline(cin, line) && !line.empty())
        grid.push_back(line); 
    string moves;
    while(true){
        string temp; cin>>temp;
        if(temp == "empty"){
            break;
        }
        moves += temp;
    }
    int R = size(grid), C = size(grid[0]);
    pair<int, int> me = {-1, -1};
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            if(grid[r][c] == '@'){
                me = {r, c};
                grid[r][c] = '.';
            }
        }
    }
    assert(me.first != -1);
    for(char move: moves){
        vector<pair<int, int>> boxes;
        auto dir = getDir(move);
        int r = me.first, c = me.second;
        bool emptySpace = false;
        while(true){
            r += dir.first;
            c += dir.second;
            if(grid[r][c] == '#'){
                break;
            }
            if(grid[r][c] == '.'){
                emptySpace = true;
                break;
            }
            assert(grid[r][c] == 'O');
            boxes.push_back({r, c});
        }
        if(emptySpace){
            me.first += dir.first;
            me.second += dir.second;
            for(auto box: boxes){
                grid[box.first][box.second] = '.';
            }
            for(auto box: boxes){
                grid[box.first + dir.first][box.second + dir.second] = 'O';
            }
        }
    }
    int res = 0;
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            if(grid[r][c] == 'O'){
                res += r * 100 + c;
            }
        }
    }
    cout<<res<<'\n';
    return 0;
}