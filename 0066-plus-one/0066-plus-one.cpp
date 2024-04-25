class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(n == 1 and digits[0] == 9) {
            return {1, 0};
        }

        for(int i=n-1; i>=0; i--) {
            if(i != 0 and digits[i] == 9) {
                digits[i] = 0;
            }
            else if(i == 0 and digits[i] == 9) {
                digits[i] = 1;
                digits.push_back(0);
            }
            else {
                digits[i] += 1;
                break;
            }
        }
        return digits;
    }
};