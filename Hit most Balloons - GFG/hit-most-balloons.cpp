// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mostBalloons(int N, pair<int, int> arr[]) {
        int ans = 0;
        for(int i = 0; i < N; i++) {
            int x1 = arr[i].first;
            int y1 = arr[i].second;
            
            int cnt = 0;
            unordered_map<double,int> mp;
            
            for(int j = 0; j < N; j++){
                int x2 = arr[j].first;
                int y2 = arr[j].second;
                
                if(x2 == x1 && y2 == y1){
                    cnt++;
                    continue;
               }
               else {
                   double slope = (double)(y2-y1) / (double)(x2-x1);
                   mp[slope]++;
               }
           }
           
           for(auto p: mp) {
               ans = max(ans,p.second+cnt);
           }
       }
       return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}  // } Driver Code Ends