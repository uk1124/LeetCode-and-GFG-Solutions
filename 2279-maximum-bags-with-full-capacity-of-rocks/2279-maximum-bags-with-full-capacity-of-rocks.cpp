class Solution {
public:
    /*APPROACH:
    Calculate all empty space for each bag.
    Sort them from small to big, including 0 empty space.
    Greedily Fill the bags, from small empty space to bigger one.
    */
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> v; 
        for(int i = 0; i < capacity.size(); i ++ ) {
            v.push_back(capacity[i] - rocks[i]); 
        }
        sort(v.begin(), v.end());
        int sum = 0, ans = 0;
        
        for(int i=0; i<v.size(); i++) {
            if(v[i] == 0) {
                ans++;
            }
            else if(additionalRocks - v[i] >= 0){
                ans++; 
                additionalRocks -= v[i] ; 
            }
        }
        return ans;
    }
};