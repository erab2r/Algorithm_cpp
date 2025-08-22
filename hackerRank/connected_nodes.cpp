#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    vector<int> nghb;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        if (par == src) {
            for (int child : adj_list[par]) {
                nghb.push_back(child);
            }
        }
    }

    if (nghb.empty()) {
        cout << -1 << "\n";
    } else {
        sort(nghb.rbegin(), nghb.rend());
        for (int node : nghb) {
            cout << node << " ";
        }
        cout << "\n";
    }
}

int main()
{   
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int q;
    cin >> q;

    while (q--) {
        int x;
        cin >> x;
        memset(visited, false, sizeof(visited));
        bfs(x);
    }

    return 0;
}