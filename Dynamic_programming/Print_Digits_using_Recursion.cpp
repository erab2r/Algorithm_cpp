#include<bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

void printDigits(long long n) {
    if (n < 10) {         
        cout << n;
        return;
    }
    printDigits(n / 10);   
    cout << " " << n % 10; 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        printDigits(N);
        cout << "\n";
    }
    return 0;
}
// Call 1: printDigits(1234)

// n = 1234 → not < 10, so go to recursive step.

// Calls printDigits(1234 / 10) → printDigits(123).

// (We will print 1234 % 10 = 4 later when recursion comes back.)