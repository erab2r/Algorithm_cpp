#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1000];
bool visited[1000];
int parent[1000];
int cycle;
void bfs( int src)
{
    queue<int>q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for(int child : adj_list[par])
        {   
            if(visited[child] && parent[par]!= child)
                cycle = true;
            if(!visited[child])
            {
                q.push(child);
                visited[child] = true;
                parent[child] = par;
            }
        }
    }
    

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
    memset(visited,0,sizeof(visited));
    cycle = false;
    for(int i = 0;i<n;i++)
    {
        if(!visited[i])
        {
            bfs(i);
        }
    }
      if(cycle)
            cout << "Cycle Detected" <<endl;
        else
            cout << "No Cycle" << endl;
}