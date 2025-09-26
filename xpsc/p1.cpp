#include <bits/stdc++.h>
using namespace std;
bool lucky = false;
int main() {
    long long n;
    cin >> n;
    while (n > 0) {
        int num = n % 10;
        if (num == 7) {
            lucky = true;
            break;
        }
        n /= 10; 
    }

    if (lucky) 
       cout << "Lucky";
    else 
       cout << "Not Lucky";

    return 0;
}
