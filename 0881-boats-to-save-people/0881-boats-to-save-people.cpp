class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        int i = 0;
        while(i < people.size()) {
            int curr = 0;
            while(i < people.size() and curr <= limit) {
                curr += people[i];
                if(curr > limit) {
                    break;
                }
                i++;
            }
            ans++;
        }
        return ans;
    }
};