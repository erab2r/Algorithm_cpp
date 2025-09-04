#include <bits/stdc++.h>
using namespace std;

int par[1005];
int group_size[1005];

int find(int node)   // O(logN)
{
    if(par[node] == -1) 
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1,int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if(leader1 == leader2) 
        return;
    if(group_size[leader1] > group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    
    memset(par, -1, sizeof(par));
    memset(group_size, 1, sizeof(group_size));
    
    int cnt_cycle_edges = 0;

    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        int leader_a = find(a);
        int leader_b = find(b);

        if(leader_a == leader_b)
        {
            cnt_cycle_edges++;
        }
        else
        {
            dsu_union(a,b);
        }
    }

    cout << cnt_cycle_edges << endl;

    return 0;
}
