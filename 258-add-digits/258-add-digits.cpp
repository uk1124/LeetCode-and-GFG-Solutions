class Solution {
public:
    int addDigits(int num) {
        while(true) {
            if(num >=0 and num <=9) {
                return num;
            }
            int rem = num%10;
            num /= 10;
            num += rem;
        }
    }
};