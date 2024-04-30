class Solution {
public:
/*APPROACH: Calculate the number of trailing zeroes in n! by counting the number of factors of 5 in 
the prime factorization of n!. Since there are fewer factors of 5 than factors of 2 in the prime 
factorization of n!, we only need to count the factors of 5.
*/
    int trailingZeroes(int n) {
        int x = 5;
        int ans = 0;

        // Continue loop until no more factors of 5 in n!
        while(n/x) {
            ans += (n/x);
            x *= 5; // Update x to the next power of 5
        }
        return ans;
    }
};