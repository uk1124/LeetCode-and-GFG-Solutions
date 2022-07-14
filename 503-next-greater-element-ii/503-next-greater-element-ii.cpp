class Solution {
public:
    /*APPROACH: 
    Imagine the input array as a concatenation of the same array, twice.
    Similar to Next Greater Element, store the index in the stack instead of the actual value. */
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);

        for(int i=0; i<n*2; i++) {
            while(!st.empty() and nums[i % n] > nums[st.top()]) {
                ans[st.top()] = nums[i % n];
                st.pop();
            }
            if(i < n) {
                st.push(i);
            }
        }
        return ans;
    }
};