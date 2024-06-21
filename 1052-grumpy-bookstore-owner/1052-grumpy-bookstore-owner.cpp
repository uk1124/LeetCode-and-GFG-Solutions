class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        if(customers.size() <= 1) return customers[0];
        int total = accumulate(customers.begin(), customers.end(), 0);
        int ans = 0;
        int i = 0, j = 0;
        int curr = 0;
        while(j < customers.size()) {
            curr += customers[j];
            if(j - i == minutes - 1) {
                ans = max(ans, total - curr);
                curr -= customers[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};