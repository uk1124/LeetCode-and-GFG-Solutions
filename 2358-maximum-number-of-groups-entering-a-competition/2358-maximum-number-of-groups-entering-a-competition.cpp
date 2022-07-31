class Solution {
public:
    /*APPROACH: Math
    1 + 2 + ... + k <= n    (k is the no. of groups)
    k(k + 1) / 2 <= n
    (k + 0.5)(k + 0.5) <= n * 2 + 0.25
    k + 0.5 <= sqrt(n * 2 + 0.25)
    k <= sqrt(n * 2 + 0.25) - 0.5 */
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        
        return sqrt(n*2 + 0.25) - 0.5;
    }
};