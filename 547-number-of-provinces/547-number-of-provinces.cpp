class Solution {
public:
    /*APPROACH: Using Union find. In union, just make any element leader of any group and make other elements as
    group member.*/
    int leader(int x, vector<int> &v) {
        if(v[x] == -1) {
            return x;
        }
        v[x] = leader(v[x], v);
        return v[x];
    }
    
    void union_(vector<int> &v, int i, int j) {
        int l_i = leader(i, v);
        int l_j = leader(j, v);
        
        if(l_i == l_j) {
            return;
        } 
        v[l_i] = l_j;        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        vector<int> v(n, -1);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    union_(v, i, j);
                }
            }
        }
        
        for(int a: v) {
            if(a == -1) {
                ans++;
            }
        }
        return ans;
    }
};