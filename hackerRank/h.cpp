#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
int level[1005][1005];
pair<int,int> parent[1005][1005];
int row, col;
vector<pair<int,int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j) {
    return (i >= 0 && i < row && j >= 0 && j < col);
}

void bfs(int si, int sj) {
    queue<pair<int,int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;


    while(!q.empty()) {
        pair<int, int> par = q.front();
        q.pop();
        int pi = par.first, pj = par.second;

        for(int i = 0;i<4;i++) {
            int ci = pi + d[i].first;
            int cj = pj + d[i].second;

            if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#') {
                vis[ci][cj] = true;
                parent[ci][cj] = {pi, pj};
                q.push({ci, cj});
            }
        }
    }
}

int main() {
    cin >> row >> col;
     int si, sj, di, dj;  
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'R'){
                si = i; sj = j;
            } else if(grid[i][j] == 'D'){
                di = i; dj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    bfs(si, sj);

    if(vis[di][dj]){
        int ci = di, cj = dj;
        while(grid[ci][cj] != 'R'){
            if(grid[ci][cj] != 'D') grid[ci][cj] = 'X';
            pair<int, int> par = parent[ci][cj];
            ci = par.first; cj = par.second;
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}














#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
pair<int,int> parent[1005][1005];
int row, col;
vector<pair<int,int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j) {
    return (i >= 0 && i < row && j >= 0 && j < col);
}

void bfs(int si, int sj) {
    queue<pair<int,int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while(!q.empty()) {
        pair<int, int> par = q.front();
        q.pop();
        int pi = par.first, pj = par.second;

        for(int i = 0;i<4;i++) {
            int ci = pi + d[i].first;
            int cj = pj + d[i].second;

            if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#') {
                vis[ci][cj] = true;
                parent[ci][cj] = {pi, pj};
                q.push({ci, cj});
            }
        }
    }
}

int main() {
    cin >> row >> col;
    int si = -1, sj = -1, di = -1, dj = -1;  
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'R'){
                si = i; sj = j;
            } else if(grid[i][j] == 'D'){
                di = i; dj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    bfs(si, sj);

    if(vis[di][dj]){
        int ci = di, cj = dj;
        while(grid[ci][cj] != 'R'){
            if(grid[ci][cj] != 'D') grid[ci][cj] = 'X';
            pair<int, int> par = parent[ci][cj];
            ci = par.first; cj = par.second;
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}

