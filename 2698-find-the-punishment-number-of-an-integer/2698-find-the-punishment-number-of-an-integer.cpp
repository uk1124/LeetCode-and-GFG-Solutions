class Solution {
public:
/*APPRAOCH:
- Iterate from 1 to \U0001d45b and compute \U0001d456^2
- Use backtracking to check if \U0001d456^2 can be split into substrings summing to \U0001d456
- If valid, add \U0001d456^2 to the total punishment sum
*/
    bool canPartition(string &s, int target, int index, int currSum) {
        if (index == s.size()) {
            return currSum == target;
        }
        int num = 0;
        for (int i = index; i < s.size(); i++) {
            num = num * 10 + (s[i] - '0');   // Form the number from digits
            if (num + currSum > target) {    // Prune if sum exceeds target
                break; 
            }
            if (canPartition(s, target, i + 1, currSum + num)) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int totalSum = 0;
        for (int i = 1; i <= n; i++) {
            int square = i * i;
            string sqStr = to_string(square);
            if (canPartition(sqStr, i, 0, 0)) {
                totalSum += square;
            }
        }
        return totalSum;
    }
};
