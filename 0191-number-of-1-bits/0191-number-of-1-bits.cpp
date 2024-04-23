class Solution {
public:
    int hammingWeight(int n) {
        string binString = "";

        while(n) {
            int rem = n % 2;
            binString += to_string(rem);
            n /= 2;
        }
        reverse(binString.begin(), binString.end());
        int ans = 0;
        for(char ch: binString) {
            if(ch == '1') ans++;
        }
        return ans;
    }
};