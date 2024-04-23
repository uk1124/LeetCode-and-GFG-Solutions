class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxi = INT_MIN, sum = 0, avg = 0;
        int i=0, j=0;
        
        while(j < nums.size())
        {
            sum = sum + nums[j];
            
            if(j-i+1 < k)
                j++;
            
            else if(j-i+1 == k)
            {
                avg = sum/k;
                maxi = max(maxi,avg);
                sum=sum-nums[i];
                i++;
                j++;
            }
        } 
        return maxi;
    }
};