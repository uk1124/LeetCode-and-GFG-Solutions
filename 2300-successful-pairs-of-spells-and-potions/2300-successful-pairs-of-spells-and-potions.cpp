class Solution {
public:
    //APPROACH: USing Binary Search
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
    
    
//      vector<int> v(s.size(),0);
//         sort(p.begin(),p.end());
        
//         for(int i=0;i<s.size();i++)
//         {
//             int h=p.size()-1;
//             int l=0;
//             int mid;
//             while(l<=h)
//             {
//                 mid = l + (h-l)/2;
                
//                 if((long long int)s[i]*(long long int)p[mid] >= suc)
//                     h = mid-1;
                
//                 else
//                     l = mid+1;
//             }
            
//             v[i] = p.size()-1-h;
//         }
        
//         return v;
//     }
};