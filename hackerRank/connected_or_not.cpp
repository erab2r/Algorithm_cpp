#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1008];

int main()
{   
    int n,e;
    cin >> n >> e;
    for(int i = 0; i < e; i++)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);  
    }

    int q;
    cin >> q;
    while(q--)
    {
        int src,dst;
        cin >> src >> dst;

        if (src == dst) {
            cout << "YES\n";
            continue;
        }

        bool found = false;
        for(int child : adj_list[src])
        {
            if(child == dst)
            {
                found = true;
                break;
            }
        }

          if(found) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }

    return 0;
}