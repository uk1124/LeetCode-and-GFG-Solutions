class Solution {
public:
/*Most Optimized APPROACH:
Using QuickSelect Algorithm
TC: O(N) [Average] [Worst-O(N^2)]   SC: O(1)
*/
    int quickSelect(vector<int>& nums, int left, int right, int pivot_index) {
        // Move the pivot to the end of the current range
        int pivot = nums[pivot_index];
        swap(nums[pivot_index], nums[right]);

        // Partition elements around the pivot
        int stored_index = left;  // Stores the index of the last element smaller than the pivot
        for(int i = left; i < right; i++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[stored_index]);
                stored_index++;
            }
        }
        // Place the pivot in its correct position
        swap(nums[right], nums[stored_index]);
        return stored_index;  // Return the final position of the pivot
    }

    int findKthLargest(vector<int>& nums, int k) {
        // Initialize left and right pointers for the search range
        int left = 0, right = nums.size() - 1;

        // Continue partitioning until we find the kth largest element
        while(true) {
            // Choose a random pivot index within the current range
            int pivot_index = rand() % (right-left+1) + left;

            // Partition array around pivot, placing elms smaller than pivot to left & larger to right 
            int new_pivot_index = quickSelect(nums, left, right, pivot_index);

            // If the pivot's final position is the kth largest, we've found it
            if(new_pivot_index == nums.size() - k) {
                return nums[new_pivot_index];
            } 
            else if(new_pivot_index > nums.size() - k) {
                // If the pivot is too far to the right, narrow the search to the left side
                right = new_pivot_index - 1;
            } 
            else {
                // If the pivot is too far to the left, narrow the search to the right side
                left = new_pivot_index + 1;
            }
        }
    }

/*APPROACH: Using Priority queue (Simple direct implementation)
TC: O(N*logk)   SC: O(k) 
*/
    // int findKthLargest(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     priority_queue<int> q;

    //     for(int num: nums) {
    //         q.push(num);
    //     }
    //     while(--k) {
    //         q.pop();
    //     }
    //     return q.top();
    // }
};