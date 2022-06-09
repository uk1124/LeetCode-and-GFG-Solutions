// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        set<pair<int,int>> s;
        int result = 0;
        
        vector<bool> vis(V,false);
        s.insert({0, 0});
        
        while(!s.empty()) {
            pair<int,int> temp = *s.begin();
            s.erase(temp);
            
            int d = temp.first;
            int x = temp.second;
            
            if(vis[x] == true) {
                continue;
            }
            
            vis[x] = true;
            result += d;
            
            for(auto val : adj[x]) {
                // x -> u (wt)
                int u = val[0];
                int wt = val[1];
                
                if(vis[u] == false) {
                    s.insert({wt, u});
                }
            }
        }
        return result;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends