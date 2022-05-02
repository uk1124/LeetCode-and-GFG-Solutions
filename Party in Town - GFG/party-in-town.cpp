// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
    // Find dist vector for each vertex and calculate max distance and minimise it by ans
public:
    void DFS(int s, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &dist){
        visited[s] = true;

        for(auto &v: adj[s]) {
            if(!visited[v]) {
                visited[v] = true;
                dist[v] = dist[s] + 1;
                DFS(v, adj, visited, dist);
            }
        }
    }
   int partyHouse(int N, vector<vector<int>> &adj) {
       int ans = INT_MAX;
       for(int i=1; i<=N; i++) {
           vector<int> dist(N+1);
           vector<bool>visited(N+1, false);
           
           if(!visited[i]) {
               dist[i] = 0;
               DFS(i, adj, visited, dist);
           }
           int maxi = 0;
           for(int i=0; i<=N; i++)
           maxi = max(maxi, dist[i]);
           ans = min(maxi, ans);
       }
       return ans;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}  // } Driver Code Ends