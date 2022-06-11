class Solution {
public:
    /*APPROACH: Think of the problem as finding subaarray whose sum is (sum - X) and its length is maximum.
                Then use sliding window concept. */
    int minOperations(vector<int>& nums, int x) {
       int len = 0, sum1 = 0, sum2 = 0;
        for(int i=0; i < nums.size(); i++) {
            sum2 += nums[i];                      //Calculating sum of whole array 
        }
			
        sum2 -= x;                             //This is sum of remaining elements, after removing x 
		
        if(sum2 == 0) {                        //Sum of array is equal to x, means we'll have to remove all elements
            return nums.size();
        }

		//sum2 is desired sum while sum1 is current sum
        int i = 0, j = 0;
        for(j = 0; j < nums.size(); j++) {
            sum1 += nums[j];
			
            while(i < nums.size() and sum1 > sum2) {  //If sum of current subarray is greater than desired sum
                sum1 -= nums[i++];
            }
				
            if(sum1 == sum2) {              //If sum of current subarray is equal to desired sum then update length
                len = max(len, j-i+1);      //We want subarray with maximum length 
            }
        }
        if(len == 0) {                      //No subarray found with desired sum
            return -1;
        }
        return nums.size() - len;
    }
};