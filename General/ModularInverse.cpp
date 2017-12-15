#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

inline ll power(ll a, ll b) {
    ll res = 1ll;
    while(b > 0) {
        if(b&1) {
            res = (res * a) %mod;
        }
        b >>= 1;
        a = (a*a) %mod;
    }
    return res;
}

ll getModInverse(ll a, ll b) {
    // Fermat's little theorem 
    // Works only when m is prime number
    return power(a, b-2);
}

ll gcd(ll a, ll b) {
    if(a==0) 
        return b;
    return gcd(b%a, a);
}

int main() {
    return 0;
}
