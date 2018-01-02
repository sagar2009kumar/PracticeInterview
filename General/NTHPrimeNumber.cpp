#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int n, m;

int primeFactor(int n, int m) {
    map<int, int> mp;
     while (n%2 == 0) {
        n = n/2;
        mp[2]++;
    }
    
    for (int i = 3; i <= sqrt(n); i = i+2) {
        while (n%i == 0) {
            mp[i]++;
            n = n/i;
        }
    }
 
    if (n > 2)
        mp[n]++;
    
    ll res = 1;
    for(auto it = mp.begin(); it!= mp.end(); it++) {
        //printf("%d %d \n",it->first, it->second);
        if(it->second%m!=0) {
            return -1;
        }else {
            int k = (it->second)/m;
            for(int p = 0; p < k; p++)
                res*= (it->first);
        }
    }
    return res;
}

int main() {
    int t ;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int res = primeFactor(m, n);
        printf("%d\n",res);
    }
	return 0;
}
