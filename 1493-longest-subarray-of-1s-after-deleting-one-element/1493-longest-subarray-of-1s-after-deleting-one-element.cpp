class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prevWindow = 0; // Initialize the size of the previous window containing only 1's
        int currWindow = 0; // Initialize the size of the current window containing only 1's
        int maxLen = 0;    

        int i = 0; 
        int n = nums.size(); 

        //To handle to case where whole array is of 1's only
        int count1s = count(nums.begin(), nums.end(), 1);
        if(count1s == n) {
            return n-1;
        }

        while (i < n) {
            while (i < n and nums[i] == 1) { // Iterate until 1's are encountered
                prevWindow++; // Increment the size of the previous window
                i++;          // Move to the next element
            }
            
            if (i < n) { // If we haven't reached the end of the array
                i++;     // Move to the next element (to skip the 0)
                while (i < n and nums[i] == 1) { // Iterate until 1's are encountered again
                    currWindow++; // Increment the size of the current window
                    i++;          // Move to the next element
                }
                
                maxLen = max(maxLen, prevWindow + currWindow); // Update the maximum length
                prevWindow = currWindow; // Update the previous window size
                currWindow = 0;          // Reset the current window size
            }
        }
    
        return maxLen; 
    }
};
