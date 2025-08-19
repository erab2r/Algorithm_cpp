#include<bits/stdc++.h>
using namespace std;
vector<int>adj_list[1005];
bool visited[1005];
int level[1005];
int parent[1005]; // To store the level of each node
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true; 
    while (!q.empty())
    {
        int par  = q.front();
        q.pop();
        cout << par << " ";
        for(int child : adj_list[par])
        {
            if(visited[child] == false)
            {
                visited[child] = true;
                q.push(child);
                level[child] = level[par] + 1; 
                parent[child] = par; // Store the parent of the child node
            }
       
        }
    }
    cout << endl; 
}
int main()
{   
    int n,e;
    cin >> n >> e;
    for(int i = 0;i<e;i++)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(visited,false,sizeof(visited));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));
    int src,dst;
    cin >> src >> dst;
    bfs(0);
    // for(int i = 0; i < n; i++)
    // {
    //     cout << i << " Parent -> " << parent[i] << endl;
    // }
    int node = dst;
    vector<int> path;
    while(node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());
    for(int x : path)
    {
        cout << x << " ";
    }

}                                                                                                             