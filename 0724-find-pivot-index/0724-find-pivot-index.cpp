class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
    
        int rsum[n], lsum[n];
        rsum[n-1] = 0;
        lsum[0] = 0;
        int sum;
        int index = -1;
        
        for(int i = 1; i<n; i++)
        {
            sum = nums[i-1];
            lsum[i] = sum + lsum[i-1];
        }
        
         for(int i = n-2; i>=0; i--)
        {
            sum = nums[i+1];
            rsum[i] = sum + rsum[i+1];
        }
        
        for(int i=0; i<n; i++)
        {
            if(lsum[i] == rsum[i])
            {
               index = i;
                break;
            }
            
                
        }
        
        return index;
    }
};