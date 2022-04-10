class Solution {
public:
    // APPROACH: Using priority queue (Min heap).
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int>> pq;
        long long mod = 1e9+7, ans = 1;
        
        for(int el: nums) {
            pq.push(el);
        }
        
        while(k--) {
            int t = pq.top();
            t += 1;
            pq.pop();
            pq.push(t);
        }
        
        while(!pq.empty()) {
            ans = (ans % mod * pq.top() % mod) % mod;
            pq.pop();
        }
        return ans;
    }
};