// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    int dp [1001][1001];
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    {
        memset(dp, -1, sizeof(dp));
        
        return memo(W, wt, val, n);
        
    }
    int memo(int W, int wt[], int val[], int n) {
        if(n == 0 or W == 0) {
            return 0;
        }
        
        if(dp[n][W] != -1) {
           return dp[n][W];
        }
        
        if(wt[n-1] <= W) {
            return dp[n][W] = max(val[n-1] + memo(W-wt[n-1], wt, val, n-1), memo(W, wt, val, n-1));
        }
        
        else {                                              // wt[n-1] > W
            return dp[n][W] = memo(W, wt, val, n-1);
        }
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends