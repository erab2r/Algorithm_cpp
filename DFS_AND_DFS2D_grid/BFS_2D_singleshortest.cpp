#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
bool visited[105][105];
int level[105][105];
int n,m;
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
bool valid(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;
    
}
void bfs(int si,int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    visited[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pair<int,int>  par  = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;
        for(int i = 0; i<4;i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if(valid(ci,cj)== true && !visited[ci][cj])
            {
                q.push({ci,cj});
                visited[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
        }
    }
    
   }
}
int main()
{
    cin >> n >> m;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin >> grid[i][j];
    int si,sj,di,dj;
    cin >> si >> sj >> di >> dj;
    memset(visited,false,sizeof(visited));
    memset(level,-1,sizeof(level));
    bfs(si,sj);
    cout << level[di][dj] << endl; // Output the distance to the destination
    return 0;
    
}