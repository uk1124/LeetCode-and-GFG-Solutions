class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        while(num) {
            if(num % 2 != 0) {
                num--;
                ans++;
            }
            if(num == 0) {
                break;
            }
            num /= 2;
            ans++;
        }
        return ans;
    }
};