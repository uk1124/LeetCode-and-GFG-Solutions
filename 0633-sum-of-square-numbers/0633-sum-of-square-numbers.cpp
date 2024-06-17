class Solution {
public:
/*APPROACH:  iterating through possible values for one integer a from 0 to sqrt(c), and verifying if the remaining 
value \U0001d450 − \U0001d44e^2 is a perfect square, indicating a valid pair (\U0001d44e,\U0001d44f). If such a pair is found, it returns true; 
otherwise, it returns false.
*/
    bool judgeSquareSum(int c) {
        for(long long i = 0; i <= sqrt(c); i++) {
            long long rem = c - i * i; // Calculate the remaining value after subtracting the square of i
            double temp = sqrt(rem);   // Compute the square root of the remaining value
            // Check if the square root is an integer
            if(floor(temp) == temp) {
                return true;
            }
        }
        return false;   // If no such pair (a, b) is found, return false
    }

/*TWO POINTER TECHNIQUE (TC is bit better)
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = sqrt(c);
        
        while (left <= right) {
            long long sumOfSquares = left * left + right * right;
            if (sumOfSquares == c) {
                return true;
            } 
            else if (sumOfSquares < c) {
                left++;
            } 
            else {
                right--;
            }
        }   
        return false;
    }
*/
};