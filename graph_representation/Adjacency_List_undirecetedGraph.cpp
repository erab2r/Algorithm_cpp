#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin >> n >> e;
    vector<int> adj_matrix[n];
    for(int i = 0; i<e;i++)
    {
        int a,b;
        cin >> a >> b;
        adj_matrix[a].push_back(b);
        adj_matrix[b].push_back(a);
    }
    for(int i = 0; i<n;i++)
    {
        cout << i << " -> ";
        for(int x : adj_matrix[i])
        {
            cout << x << " ";       
        }
        cout << endl;
    }
    return  0;
}  