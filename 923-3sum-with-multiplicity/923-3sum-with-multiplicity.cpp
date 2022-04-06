class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map <long long, long long> mp;
        long long ans = 0;
        for(int i=0; i<arr.size(); i++) {
            mp[arr[i]]++;
        }
        
        for(auto it1: mp) {
            for(auto it2: mp) {
                long long i = it1.first, j = it2.first, k = target - j - i;
                if(mp.count(k) == 0) {
                    continue;
                }
                if(i == j and j == k) {
                   ans += mp[i] * (mp[i] - 1) * (mp[i] - 2) / 6; 
                }
                else if(i == j and j != k) {
                    ans += mp[i] * (mp[i] - 1) / 2 * mp[k];
                }
                else if(i < j and j < k) {
                    ans += mp[i] * mp[j] * mp[k];
                }
            }
        }
        return (ans % int(1e9+7));
    }
};