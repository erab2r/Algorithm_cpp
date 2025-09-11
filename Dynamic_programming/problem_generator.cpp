#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        string s;
        cin >> s;
        int freq[7] = {0};
        for(char c : s)
        {
            freq[c-'A']++;
        }

    }
    return 0;
}