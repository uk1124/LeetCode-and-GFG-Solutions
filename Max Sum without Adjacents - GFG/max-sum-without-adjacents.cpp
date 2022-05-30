// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int f(int indx, int *arr, vector<int> &dp) {
        if(indx == 0) {
            return arr[indx];
        }
        if(indx < 1) {
            return 0;
        }
        if(dp[indx] != -1) {
            return dp[indx];
        }
        int pick = arr[indx] + f(indx-2, arr, dp);
        int notPick = 0 + f(indx-1, arr, dp);
        
        return dp[indx] = max(pick, notPick);
    }

	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n, -1);
	    
	    return f(n-1, arr, dp);
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends