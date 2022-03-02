// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long countStrings(string S)
    {
        long long freq[26] = {0};
        for(int i = 0; i < S.length(); i++) {
            freq[S[i] - 'a']++;
        }
        long long reps = 0;
        for(int i = 0; i < 26; i++) {
            reps += freq[i]*(freq[i] - 1)/2;
        }
        long long n = S.length();
        return reps > 0 ? 1 + (n*(n-1))/2 - reps : (n*(n-1))/2 - reps;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends