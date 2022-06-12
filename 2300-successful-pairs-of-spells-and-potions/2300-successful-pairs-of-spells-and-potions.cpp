class Solution {
public:
    //APPROACH: USing Binary Search
    /*Binary search the index of first potion >= need in the sorted potions. (need = success / spell)
    The number of potions that are successful are potions.length - index
    Accumulate the result ans and finally return it. */
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans(spells.size());
        int n = potions.size();
        sort(potions.begin(), potions.end());
        
        for(int i=0; i<spells.size(); i++) {
            int lo = 0;
            int hi = n - 1;
            while(lo <= hi) {
                int mid = (lo + hi)/2;
                if((long long)spells[i] * (long long)potions[mid] >= success) {
                    hi = mid - 1;
                }
                else {
                    lo = mid + 1;
                }
                ans[i] = (n - lo);
            }
        }
        return ans;
    }
};