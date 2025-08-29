#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
bool visited[10005][10005];   

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int si, int sj, vector<string>& grid) {
    visited[si][sj] = true;
    for(int i = 0; i < 4; i++) {   
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] == '.') {
            dfs(ci, cj, grid);
        }
    }
}

int main() {
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++)
        cin >> grid[i];

    int si, sj, di, dj;
    cin >> si >> sj;
    cin >> di >> dj;

    memset(visited, false, sizeof(visited));

    if(grid[si][sj] == '.')
        dfs(si, sj, grid);

    if(visited[di][dj])
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}