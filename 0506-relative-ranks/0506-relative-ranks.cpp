class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        if(score.size() == 1) {
            return {"Gold Medal"};
        }
        else if(score.size() == 2) {
            return {"Gold Medal", "Silver Medal"};
        }
        else if(score.size() == 3) {
            return {"Gold Medal", "Silver Medal", "Bronze Medal"};
        }
        unordered_map<int, string> mp;
        vector<int> v = score;
        sort(v.begin(), v.end(), greater<int>());

        mp[v[0]] = "Gold Medal";
        mp[v[1]] = "Silver Medal";
        mp[v[2]] = "Bronze Medal";
        for(int i=3; i<v.size(); i++) {
            mp[v[i]] = to_string(i+1);
        }

        vector<string> ans;
        for(int el: score) {
            ans.push_back(mp[el]);
        }
        return ans;
    }
};