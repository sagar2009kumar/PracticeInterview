#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
const int N = 1e3+2;
ll fact[N];

void preFact() {
    fact[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = (fact[i-1]*(ll)i)%mod;
    }
}

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
    // inverse is a^(b-2)
    return power(a, b-2);
}

ll getNCR(ll n, ll r) {
    if(n < r) return 0;
    ll num = fact[n];
    ll den = (fact[n-r]*fact[r])%mod;
    //printf("%llu %llu\n",num,den);
    den = getModInverse(den, mod);
    return (num*den)%mod;
}

int main()
 {
	//code
	preFact();
	int t, n, r;
	scanf("%d",&t);
	ll res = 0;
	while(t-->0) {
	    scanf("%d%d",&n,&r);
	    res = getNCR(n, r);
	    printf("%llu\n",res);
	}
	return 0;
}
