class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() != 1) {
            sort(stones.begin(), stones.end());
            
            int x = stones.rbegin()[0];
            int y = stones.rbegin()[1];
            int t = x-y;
            stones.pop_back();
            stones.pop_back();
            stones.push_back(t);
        }
        return stones[0];
    }
};