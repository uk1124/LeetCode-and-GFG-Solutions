class Solution {
public:
    int numTilings(int n) {
        int M = 1e9 + 7;
        vector<int> v(1001);
        v[1] = 1;
        v[2] = 2;
        v[3] = 5;
        v[4] = 11;
        if(n < 5) {
            return v[n];
        }
        for(int i=5; i<=n; i++) {
            v[i] = ( (v[i-1] * 2 % M) + (v[i-3] % M) )% M;        
        }
        return v[n]; 
    }
};