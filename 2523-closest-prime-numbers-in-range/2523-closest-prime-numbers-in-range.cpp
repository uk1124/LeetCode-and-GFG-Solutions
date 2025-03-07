class Solution {
public:
    vector<bool> sieveOfEratosthenes(int n) {
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false; 

        for (int p = 2; p * p <= n; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    prime[i] = false; 
                }
            }
        }
        return prime;
    }   

    vector<int> closestPrimes(int left, int right) {
        vector<bool> primes = sieveOfEratosthenes(right);
        int prev = -1, num1 = -1, num2 = -1, minDiff = INT_MAX;
        
        for (int i = left; i <= right; i++) {
            if (primes[i]) {
                if (prev != -1 and (i - prev) < minDiff) {
                    minDiff = i - prev;
                    num1 = prev;
                    num2 = i;
                }
                prev = i;
            }
        }

        return (num1 == -1) ? vector<int>{-1, -1} : vector<int>{num1, num2};
    }
};