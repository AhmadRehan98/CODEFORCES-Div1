#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
long long power(long long n, long long p){
    long long cur, res;
    cur = n;
    res = 1;
    while(p){
        if(p%2 == 1){
            res *= cur;
             res %= mod;
        }
        p /= 2;
        cur *= cur;
        cur %= mod;
    }
    return res;
}
int main() {
    long long n;
    cin >> n;
    if (n == 0) cout << 1;
    else cout << ( ( (power(2,n) + 1 )%mod ) * (power(2,n-1)%mod) )% mod;
}
