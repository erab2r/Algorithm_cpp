#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
bool visited[105][105];
vector<pair<int,int>> d ={{-1,0},{1,0},{0,-1},{0,1}}; 
void dfs(int si, int sj)
{
    
}
{
    cout << "(" << i << "," << j << ") ";
    visited[i][j] = true;
    for(auto [di,dj] : d)
    {
        int ni = i + di;
        int nj = j + dj;
        if(ni >= 0 && ni < 105 && nj >= 0 && nj < 105 && !visited[ni][nj] && grid[ni][nj] == '.')
        {
            dfs(ni, nj);
        }
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin >> grid[i][j];
    int si,sj;
    cin >> si >> sj;
    memset(visited,false,sizeof(visited));
    dfs(si,sj);
    return 0;
        
    
}