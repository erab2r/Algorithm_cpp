#include <bits/stdc++.h>
using namespace std;

int dp[1000005]; 
bool can_Reach(long long cur, long long target) {
    if (cur == target) 
        return true;
    if (cur > target) 
        return false;
    if (dp[cur] != 0) 
        return dp[cur] == 1;

    bool res = can_Reach(cur * 2, target) || can_Reach(cur + 3, target);
    
    if(res)
        dp[cur] = 1;
    else
        dp[cur] = -1;

    return res;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        memset(dp, 0, sizeof(dp));
        if (can_Reach(1, n)) 
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}