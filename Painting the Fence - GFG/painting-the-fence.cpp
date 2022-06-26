// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long mod = 1000000007;
    
    long long solve(int n, int k, vector <long long int> &dp) {
         if(n == 1) {
            return k;
        }
        if(n == 2) {
            return ((long long)k*(long long)k)%mod;
        }
        if(n == 0 or k == 0) {
            return 0;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        long long ans = ((long long)(k-1)*(solve(n-1,k, dp)%mod+solve(n-2,k, dp)%mod)%mod)%mod;
        return dp[n] = ans%mod;
    }
    
    long long countWays(int n, int k) {
        vector <long long int> dp(n+1, -1);
        return solve(n, k, dp);
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends