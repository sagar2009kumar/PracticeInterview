#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

/* Fermat's little theorem 
 * if a > 0 and p is positive and prime then
 * a^(p-1) is 1 mod p
 * then dividing by a both sides we get a^(p-2) is a^(-1) mod p
 * this can be proof by the reducing fact.
 * reducing fact tells that 
 * a, 2a, 3a, ... (p-1)a is congruent to 
 * 1, 2, 3, 4, ... (p-1) thus 
 * a*2a*3a*4a*...(p-1)a is congruent to 1*2*3*... (p-1)
 * thus cancelling 1*2*3*...(p-1) from both sides
 * we get a^(p-1) is congruent to 1 mod p
 */

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
