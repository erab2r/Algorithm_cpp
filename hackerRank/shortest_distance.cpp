#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin >> n >> e;
    long long adj_mat[n][n];  

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = LLONG_MAX;
        }
    }

    while(e--)
    {
        int a,b;
        long long c;
        cin >> a >> b >> c;
        a--, b--;
        adj_mat[a][b] = min(adj_mat[a][b], c); 
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(adj_mat[i][k]!=LLONG_MAX && adj_mat[k][j]!=LLONG_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
            }
        }
    }

    bool cycle = false;
    for(int i=0;i<n;i++)
    {
        if(adj_mat[i][i] < 0 )
            cycle = true;
    }

    int Q;
    cin >> Q;

    if(cycle)
    {
        while(Q--) cout << -1 << "\n";
    }
    else
    {
        while(Q--)
        {
            int x,y;
            cin >> x >> y;
            x--, y--; 
            if(adj_mat[x][y] == LLONG_MAX) 
                cout << -1 << "\n";
            else 
                cout << adj_mat[x][y] << "\n";
        }
    }

    return 0;
}

