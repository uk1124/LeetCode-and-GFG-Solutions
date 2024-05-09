class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());

        long long ans = 0;
        
        while(k--) {
            int n = happiness.size();
            ans += (happiness[n-1] - 1);
            happiness.pop_back();

            // for(int i = 0; i < n; i++) {
            //     if(happiness[i] != 0) {
            //         happiness[i] -= 1;
            //     }
            // }
        }
        return ans+1;
    }
};