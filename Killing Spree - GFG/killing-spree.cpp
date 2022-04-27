// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    long long int killinSpree(long long int n)
    {
        long long int k = n, i = 1;
        while(k >= i*i) {
            k -= (i*i);
            i++;
        }
        return i-1;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n; cin>>n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout<<ans<<"\n";
    }
    return 0;
}
  // } Driver Code Ends