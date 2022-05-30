// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int solve(int i, int j, int n, int m, vector<vector<int>>& matrix, vector<vector<int>> &dp) {
        if(dp[i][j] != -1)  {
            return dp[i][j];
        }
        
        int res = 0;
        if(j - 1 >= 0 and matrix[i][j - 1] > matrix[i][j]) {
            res = max(res, solve(i, j - 1, n, m, matrix, dp));
        }
        if(i - 1 >= 0 and matrix[i - 1][j] > matrix[i][j]) {
            res = max(res, solve(i - 1, j, n, m, matrix, dp));
        }
        if(j + 1 < m and matrix[i][j + 1] > matrix[i][j]) {
            res = max(res, solve(i, j + 1, n, m, matrix, dp));
        }
        if(i + 1 < n and matrix[i + 1][j] > matrix[i][j]) {
            res = max(res, solve(i + 1, j, n, m, matrix, dp));
        }
            
        return dp[i][j] = 1 + res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res = max(res, solve(i, j, n, m, matrix, dp));
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends