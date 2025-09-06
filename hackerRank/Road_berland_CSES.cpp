#include <bits/stdc++.h>
using namespace std;
int par[100005];
int group_size[100005];
int find(int node)
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
    if(group_size[leader1] > group_size[leader2])
    {
        par[]
    }
}
int main()
{

}