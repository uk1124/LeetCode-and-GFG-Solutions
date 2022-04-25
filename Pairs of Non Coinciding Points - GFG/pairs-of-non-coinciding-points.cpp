// { Driver Code Starts

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int numOfPairs(int X[], int Y[], int N) {
        map <int,int> x;
        map <int,int> y;
        map <pair<int,int>,int> xy;
        
        for(int i=0; i<N; i++) {        // Count distinct x , y ,point(x,y)
            x[X[i]]++;
            y[Y[i]]++;
            xy[{X[i],Y[i]}]++;
        }
        
         int xans=0,yans=0,xyans=0;
       
        for(auto it: x) {               // Count pair with same x
            int f = it.second;
            int af = f*(f-1)/2;
            xans+=af;
        }
        
        for(auto it: y) {               // Count pair with same y
            int f = it.second;
            int af = f*(f-1)/2;
            yans += af;
        }
        
        for(auto it: xy) {              // Count pair with same xy
            int f = it.second;
            int af = f*(f-1)/2;
            xyans += af;
        }
        return xans+yans-2*xyans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int X[N], Y[N];
        
        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>Y[i];

        Solution ob;
        cout << ob.numOfPairs(X,Y,N) << endl;
    }
    return 0;
}  // } Driver Code Ends