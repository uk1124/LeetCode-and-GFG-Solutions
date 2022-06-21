// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        int n = s.size();
        long long int mod = 1000000007;
        int dp[3][n+1];
        for(int i=0; i<3; i++) {
            for(int j=0; j<=s.length(); j++) {
                if(j == 0) {
                    dp[i][j] = 0;
                }
                else {
                    if(i == 0) {
                        if(s[j-1] == 'a') {
                            dp[i][j] = ((dp[i][j-1]*2) % mod+1) % mod;
                        }
                        else {
                            dp[i][j] = (dp[i][j-1]) % mod;
                        }
                    }
                    if(i == 1) {
                        if(s[j-1] == 'b') {
                            dp[i][j] = ((dp[i][j-1]*2) % mod + (dp[i-1][j]) % mod) % mod;
                        }
                        else {
                            dp[i][j] = (dp[i][j-1]) % mod;
                        }
                    }
                    if(i == 2) {
                        if(s[j-1] == 'c') {
                            dp[i][j] = ((dp[i][j-1]*2) % mod + (dp[i-1][j]) % mod) % mod;
                        }
                        else {
                            dp[i][j] = (dp[i][j-1]) % mod;
                        }
                    }
                }
            }
        }
        return dp[2][n];
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends