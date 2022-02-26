// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        int res=INT_MAX;
        int a=0, b=0, c=0, j=0;
        for(int i=0; i<S.length(); i++) {
           if(S[i] == '0')      a++;
           else if(S[i] == '1') b++;
           else if(S[i] == '2') c++;
           
           while(a>0 && b>0 && c>0) {
               res = min(res, i-j+1);
               if(res == 3)  {
                   return 3;
               }
               if(S[j] == '0')      a--;
               else if(S[j] == '1') b--;
               else if(S[j] == '2') c--;
               j++;
           }
       }
       if(res == INT_MAX) {
           return -1;
       }
       return res;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends