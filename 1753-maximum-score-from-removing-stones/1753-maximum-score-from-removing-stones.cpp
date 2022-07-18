class Solution {
public:
    /*APPROACH: For simplicity, Preprocess the input to ensure that a > b > c. Then we pick stones from a and b
    piles, and recursively. */
    int maximumScore(int a, int b, int c) {
        if(a < b) {
            return maximumScore(b, a, c);
        }
        if(b < c) {
            return maximumScore(a, c, b);
        }
        
        if(b == 0) {
            return 0;
        } 
        return 1 + maximumScore(a-1, b-1, c); 
    }
};