//Question: You will be given an undirected graph as input. You need to tell the number of nodes in each component in ascending order.

#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];
int cnt = 0;
void dfs(int src)
{
    visited[src] = true;
    cnt++;
    for(int child : adj_list[src])
      if(!visited[child])
      {
          dfs(child);
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
    memset(visited,false,sizeof(visited));
    vector<int> components;
    for(int i = 0; i<n; i++)
    {
        if(visited[i] == false)
        {
            cnt = 0;
            dfs(i);
            components.push_back(cnt);
        }
    }
    sort(components.begin(),components.end());
    for( int x : components)
        cout << x << " ";
    return 0;
}