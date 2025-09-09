#include<bits/stdc++.h>
using namespace std;
int fibo(int n)
{
    // if(n==1)
    //     return 1;
    // if(n==0)
    //     return 0;
    if(n<2)
        return n;
    return fibo(n-1) + fibo(n-2);
}
int main()
{   
    cout <<fibo(8);
    return 0;
}