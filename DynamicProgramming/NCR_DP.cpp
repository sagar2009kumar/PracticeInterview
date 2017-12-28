
// https://www.geeksforgeeks.org/dynamic-programming-set-9-binomial-coefficient/

// Based on the following recurrence relation 

// IMPORTANT :: 
// [n, r] = [n-1, r] + [n-1, r-1] where [n, r] represent the nCr of the number

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
const int N = 1e3+7;
const int R = 807;
ll fact[N][N];

void preCal() {
    // setting the diagonal and the first element of the table to be 1
    for(int i = 0; i < N; i++) fact[i][i] = 1, fact[i][0] = 1;
    // setting all the other elements of the table
    for(int col = 1; col < N; col++ ) {
        for(int row = col+1; row < N; row++) {
            fact[row][col] = (fact[row-1][col-1] + fact[row-1][col])%mod;
        }
    }
}

int main() {
	preCal();
	int t, n, r;
	scanf("%d",&t);
	ll res = 0;
	while(t-->0) {
	    scanf("%d%d",&n,&r);
	    if( n < r) res = 0; else res = fact[n][r];
	    printf("%llu\n",res);
	}
	return 0;
}
