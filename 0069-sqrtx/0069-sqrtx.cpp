class Solution {
public:
    int mySqrt(int x) {
        int i = 0;
        while(i*i <= x) {
            i++;
        }
        return i-1;
    }
};