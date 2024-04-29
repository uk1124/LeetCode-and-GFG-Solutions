class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
         vector<bool> ans;
        int max_candies = *max_element(candies.begin(), candies.end());

        for(int el: candies) {
            if(el + extraCandies >= max_candies) {
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};