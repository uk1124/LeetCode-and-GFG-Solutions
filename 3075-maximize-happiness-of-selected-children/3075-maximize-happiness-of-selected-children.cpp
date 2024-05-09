class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());

        long long ans = 0;
        int sub = 0;
        while(k--) {
            int n = happiness.size();
            if(happiness[n-1] > sub) {
                ans += (happiness[n-1] - sub);
            }
            happiness.pop_back();
            sub++;

        }
        return ans;
    }
};