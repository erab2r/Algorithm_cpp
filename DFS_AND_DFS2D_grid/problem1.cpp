//Question: You will be given an undirected graph as input. Then you will be given a node N. You need to tell the number of nodes that can be visited from node N.

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
    int start_node;
    cin >> start_node;
    dfs(start_node);
    cout << cnt << endl;
    return 0;
}