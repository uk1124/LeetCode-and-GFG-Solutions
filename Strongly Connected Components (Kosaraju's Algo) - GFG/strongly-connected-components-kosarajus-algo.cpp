// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    public:
    void dfstopo(int source, vector<bool> &visited, vector<int> trans[]) {
        visited[source] = true;
        for(auto neighbour: trans[source]) {
            if(!visited[neighbour]) {
            dfstopo(neighbour, visited, trans);
            }
        }
    }
    
    void dfs(int source, vector<bool> &visited, vector<int> adj[], stack<int> &s) {
        visited[source] = true;
        for(auto neighbour: adj[source]) {
            if(!visited[neighbour]) {
                dfs(neighbour, visited, adj, s);
            }
        }
        s.push(source);
    }
    
    //Function to find number of strongly connected components in the graph
    int kosaraju(int v, vector<int> adj[]) {
     
    //Step 1: Topological sort
    stack<int> s;
    vector<bool> visited(v, false);
    for(int i=0; i<v; i++) {
        if(!visited[i]) {
            dfs(i, visited, adj, s);
        }
    }
    
    //Step 2: Transpose 
    vector<int> trans[v];
    for(int i=0; i<v; i++) {
     visited[i] = false;
     for(auto x: adj[i]) {
     trans[x].push_back(i);
     
    }
    
   //Step 3: Do the dfs on the topological sort stack 
   int ans=0;
   while(!s.empty()) {
       int temp = s.top();
       s.pop();
       if(!visited[temp]) {
           ans++;
           dfstopo(temp, visited, trans);
       }
   }
   return ans;
   }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends