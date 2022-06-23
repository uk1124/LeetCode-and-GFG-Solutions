// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	#define M 1000000007
	int TotalWays(int N) {
	    if(N == 1) {
	        return 4;
	    }
	    if(N == 2) {
	        return 9;
	    }
	    long long prev1 = 2, prev2 = 3;
	    for(int i=3; i<=N; i++){
	        long long temp = (prev1 % M + prev2 % M) % M;
	        prev1 = prev2;
	        prev2 = temp;
	    }
	    return (prev2*prev2) % M;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends