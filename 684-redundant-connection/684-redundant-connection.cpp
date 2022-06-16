//APPROACH: Using Union Find
class UnionFind {           //Union Find Class
    vector<int> parent, size;
public:
    UnionFind(int n) {
        parent.resize(n); size.resize(n);
        for (int i=0; i<n; i++) {
            parent[i] = i; 
            size[i] = 1;
        }
    }
    
    int find(int x) {   /*Outputs a unique id so that two nodes have the same id if and only if they are in the same
                        connected component.*/
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]); //Path compression
    }
    
    bool Union(int u, int v) { /*Connects the components with id find(u) and find(v) together. If it already                                        connected then return False, else return True.*/
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) {             //Return False if u and v are already union
            return false;
        }
        if (size[pu] > size[pv]) {  //Union by larger size
            size[pu] += size[pv];
            parent[pv] = pu;
        } 
        else {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);
        for (auto &e : edges) /*We iterate edge [u, v] in edges, if u and v is already connected in the UnionFind
                                then we return that redundant edge.*/
            if (uf.Union(e[0]-1, e[1]-1) == false) {
                return {e[0], e[1]};
            }
        return {};
    }
};