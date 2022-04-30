class Solution {
public:
    //APPROACH: Use prefix and suffix sum arrays.
    int minimumAverageDifference(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> prleft(n), prright(n);
        set<pair<long long,long long>> s;
        
        prleft[0] = nums[0];
        prright[n-1] = nums[n-1];
        for(int i=1; i<n; i++) {
            prleft[i] += prleft[i-1] + nums[i];
        }
        
        for(int i=n-2; i>=0; i--) {
            prright[i] += prright[i+1] + nums[i];
        }
        
        for(int i=0; i<n; i++) {
            prright[i] = prright[i] - nums[i];
        }
        
        long long min_ans = prleft[n-1];
        s.insert({min_ans/n, n-1});
        
        for(int i=0; i<n-1; i++) {
            long long a = prleft[i]/(i+1);
            long long b = (prright[i]) / (n-i-1);
           
            if(abs(a-b) <= min_ans) {
                min_ans = abs(a-b);
                s.insert({min_ans,i});
            }
        }
        auto ans = *s.begin();
        return ans.second;
    }
};