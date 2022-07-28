class Solution {
public:
    //APPROACH: Using DFS and Coloring algorithm
    bool hasEvenLengthCycle(vector<vector<int>>& graph, int curr, int color, vector<int>&colors) {
        if(colors[curr] != -1) {
            return colors[curr] == color;
        }
        //If not colored then color it 
        colors[curr] = color;
        
        //Check for neighbours 
        for(int neigh: graph[curr]) {
            if(hasEvenLengthCycle(graph, neigh, 1-color, colors) == false) {
                // 1 - color will handle both changing colors 0 to 1 and 1 to 0 
                return false;
            }
        }   
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
       int n = graph.size(); 
       vector <int> colors(n, -1);
       for(int curr=0; curr<n; curr++) {
           //If already colored then skip 
           if(colors[curr] != -1) {
               continue; 
           }
           //Check for even length cycle 
           if(hasEvenLengthCycle(graph, curr, 0, colors) == false) {
               return false;
           }
       }
        return true;
   }
};