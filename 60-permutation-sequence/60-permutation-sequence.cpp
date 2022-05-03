class Solution {
public:
    /*LOGIC: For n numbers the permutations can be divided to (n-1)! groups, for n-1 numbers can be divided to
    (n-2)! groups, and so on. Thus k/(n-1)! indicates the index of current number, and k%(n-1)! denotes
    remaining index for the remaining n-1 numbers.
    We keep doing this until n reaches 0, then we get n numbers permutations that is kth. */
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> nums;
        
        for(int i=1; i<n; i++) {
            fact *= i;
            nums.push_back(i);
        }
        
        nums.push_back(n);
        string ans = "";
        k = k-1;
        
        while(true) {
            ans += to_string(nums[k/fact]);
            nums.erase(nums.begin() + k/fact);
            
            if(nums.size() == 0) {
                break;
            }
           
            k %= fact;
            fact /= nums.size();
        }
        return ans;
    }
};