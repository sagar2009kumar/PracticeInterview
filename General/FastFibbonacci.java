import java.util.*;
import java.lang.*;
import java.io.*;

/* The basic idea of the programming is the following fact
 * {{fib[n+1], fib[n]}, {fib[n], fib[n-1]}} is the actual matrix
 * the basic base matrix for which is equal to {{1, 1}, {1, 0}}
 */


class GFG {
    static int n;
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
	public static void main (String[] args) throws IOException {
		//code
		int t = Integer.parseInt(bf.readLine());
		long n;
		long res = 0;
		while(t-->0) {
		    n = Long.parseLong(bf.readLine());
		    if(n==1 || n==2) {
		        System.out.println(1);
		        continue;
		    }
		    res = fn(n-2);
		    System.out.println(res);
		}
	}
	
	static long mod = (long)1e9+7;
	
	static long fn(long n) {
	    long res[][] = new long[2][2];
	    res[0][0] = 1; res[0][1] = 1;
	    res[1][0] = 1; res[1][1] = 0;
	    
	    long a[][] = new long[2][2];
	    a[0][0] = 1; a[0][1] = 1;
	    a[1][0] = 1; a[1][1] = 0;
	    
	    while(n > 0) {
	        if(n%2==1) {
	            res = multiply(res, a);
	        }
	        n>>=1;
	        a = multiply(a, a);
	    }
	    return res[0][0]%mod;
	}
	
	static long[][] multiply(long a[][], long b[][]) {
	    long[][] c = new long[2][2];
	    for(int i = 0; i < 2; i++) {
	        for(int j = 0; j < 2; j++) {
	            c[i][j] = 0;
	            for(int k = 0; k < 2; k++) {
	                c[i][j] = (c[i][j] + (a[i][k]*b[k][j])%mod)%mod;
	            }
	        }
	    }
	    return c;
	}
}
