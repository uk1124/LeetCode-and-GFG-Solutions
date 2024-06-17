class Solution {
public:
    bool judgeSquareSum(int c) {
        long long t = c;
        for(long long i=1; i<=sqrt(c); i++) {
            t = c;
            t -= i*i;
            double temp = sqrt(t);
            if(floor(temp) == ceil(temp)) {
                return true;
            }
        }
        return false;
    }
};