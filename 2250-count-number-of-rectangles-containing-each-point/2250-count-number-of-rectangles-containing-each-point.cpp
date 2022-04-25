class Solution {
public:
    int binsearch(vector<int> &nums, int x) {
        int lo = 0, hi = nums.size()-1;
        int tans = nums.size();
        
        while(lo <= hi) {
            int mid = (lo+hi) / 2;
            
            if(nums[mid] >= x) {
                tans = mid;
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }
        return tans;
    }
    
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        unordered_map <int,vector<int>> mp;
        
        for(int i=0; i<rectangles.size(); i++){       
            mp[rectangles[i][1]].push_back(rectangles[i][0]);
        }
        
		// Sort the containers to apply binary search
        for(int i=0; i<=100; i++){
            sort(mp[i].begin(), mp[i].end());
        }
        
        vector<int> ans;
        for(auto p: points) {
            int x = p[0], y = p[1];
            int ct = 0;
            for(int j= y; j<=100; j++){
                if(mp.find(j) != mp.end()){
                    ct += mp[j].size() - binsearch(mp[j], x);
					// BS return the idx in array from which the values are >= x.
					// The values at this and right of this are the lengths possible,
					// so substract by size of array to get the number.
                }
            }
            ans.push_back(ct);
        }
        
        return ans;
    }
};