#include <bits/stdc++.h>
using namespace std;
bool can_reach(long long n)
{
    if(n==1)
        return true;
    if(n%10 == 0 && can_reach(n/10))
        return true;
    if(n%20 == 0 && can_reach(n/20))
        return true;
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if(can_reach(n))
              cout << "YES\n";
        else
            cout << "NO\n";
    }
    
}