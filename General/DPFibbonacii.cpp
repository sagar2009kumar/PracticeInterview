#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
const int N = 1e3+2;
ll fib[N];

int main()
 {
	//code
	fib[0] = 0; fib[1] = 1;
	for(int i = 2; i <= 1000; i++) {
	    fib[i] = (fib[i-1] + fib[i-2])%mod;
	}
	int t; 
	scanf("%d",&t);
	while(t-->0) {
	    int k;
	    scanf("%d",&k);
	    printf("%llu\n",fib[k]);
	}
	return 0;
}
