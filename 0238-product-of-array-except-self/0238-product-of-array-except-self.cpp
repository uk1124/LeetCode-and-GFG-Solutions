class Solution {
public:
/*APPROACH: We don't actually need separate array to store prefix product and suffix products, we can 
do all the approach discussed in the below method directly onto our final answer array.
TC: O(N), SC: O(1)
*/
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1); // Initialize the answer vector with all elements as 1

        int curr = 1;
        // Calculate the product of all elements to the left of the current element
        for(int i = 0; i < n; i++) {
            ans[i] *= curr;  
            curr *= nums[i]; 
        }

        curr = 1;
        // Calculate the product of all elements to the right of the current element
        for(int i = n - 1; i >= 0; i--) {
            ans[i] *= curr; 
            curr *= nums[i]; 
        }
        return ans; 
    }
};

/* Using Prefix Product array and Suffix Product array.
TC: O(N), SC: O(N)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), suff(n), ans(n);

        pre[0] = 1;
        suff[n-1] = 1;

        for(int i=1; i<n; i++) {
            pre[i] = pre[i-1] * nums[i-1];
        }

        for(int i=n-2; i>=0; i--) {
            suff[i] = suff[i+1] * nums[i+1];
        }

        for(int i=0; i<n; i++) {
            ans[i] = pre[i] * suff[i];
        }
        return ans;
    }
*/