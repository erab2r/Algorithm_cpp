#include<bits/stdc++.h>
using namespace std;
vector<int>adj_list[1005];
bool visited[1005];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << " ";
        for(int child : adj_list[par])
        {
            if(visited[child] == false)
            {
                visited[child] = true;
                q.push(child);
            }
        }

    }
    cout << endl;
    

}
int main()
{   
    int n,e;
    cin >> n >> e;
    for(int i = 0; i<e;i++)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); 
    }
    memset(visited,false,sizeof(visited));
    int src,dst;
    cin >> src >> dst;
    bfs(0);
    if(visited[dst])
        cout << "Yes, there is a path from " << src << " to " << dst << endl;
    else
        cout << "No, there is no path from " << src << " to " << dst << endl;
     return 0;
}
