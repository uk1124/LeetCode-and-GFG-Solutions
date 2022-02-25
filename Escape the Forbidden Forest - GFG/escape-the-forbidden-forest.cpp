// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 


 // } Driver Code Ends
class Solution
{
    public:
    int build_bridges(string str1, string str2)
    {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp (m+1,vector<int>(n+1,0));
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                int temp = 0;
                if(str1[i-1] == str2[j-1]){
                    temp = 1;
                }
                dp[i][j] = max({dp[i-1][j], dp[i][j-1], temp+dp[i-1][j-1]});
            }
        }
        return dp.back().back();
    }
};

// { Driver Code Starts.
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        string str1,str2;
        cin >> str1 >> str2;
        Solution obj;
        cout<<obj.build_bridges(str1,str2)<<endl;
    } 
    return 0;
} 
  // } Driver Code Ends