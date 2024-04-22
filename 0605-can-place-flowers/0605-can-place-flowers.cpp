class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;  // A count variable to keep track of the no of flowers that can be planted
        int size = flowerbed.size();
        int i = 0;
        
        while(i < size) {
            // Check if the current plot and its adjacent plots are empty
            if (flowerbed[i] == 0 and (i == 0 or flowerbed[i-1] == 0) and (i == size-1 or flowerbed[i+1] == 0)) {
                flowerbed[i] = 1; // Plant a flower in the current plot
                count++;          // Increment the count of planted flowers
            }
            i++; 
        }
        
        // Check if the number of planted flowers is greater than or equal to n
        return count >= n;
    }
};
