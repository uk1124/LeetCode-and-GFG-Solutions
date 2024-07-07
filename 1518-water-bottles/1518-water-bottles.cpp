class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int exchange = ans;

        while(numBottles >= numExchange) {
            int can_exchange = numBottles/numExchange;
            int rem = numBottles%numExchange;

            ans += can_exchange;
            numBottles = can_exchange + rem;
        }
        return ans;
    }
};