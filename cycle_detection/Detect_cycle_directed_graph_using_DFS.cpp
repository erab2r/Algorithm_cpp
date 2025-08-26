#include<bits/stdc++.h>
using namespace std;
bool visited[105];
vector<int> adj_list[105];
bool path_vis[105];
bool cycle;

void dfs(int src)
{
    visited[src] = true;
    path_vis[src] = true;
        for(int child : adj_list[src])
        {
            if(visited[child] && path_vis[child])
                cycle = true;
            if(!visited[child])
            {   
                dfs(child);
            }
        }
        path_vis[src] = false;
    
}

int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }
    memset(visited,false,sizeof(visited));
    memset(path_vis,-1,sizeof(path_vis));
    cycle = false;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
            dfs(i);
    }
    if(cycle)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";
    return 0;
}