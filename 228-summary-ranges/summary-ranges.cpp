class Solution {
public:
/* APPROACH: Run a loop in the array and when it differs from our expected number we break the loop and store it in answer. After that we shift to our next element and again start doing that.
*/
    vector<string> summaryRanges(vector<int>& arr) {
        int n = arr.size();
        vector<string> ans;
        string temp = ""; // Temporary string that stores all possible answer
        
        for(int i=0; i<n; i++) {
            int j = i; // Declare anthor pointer that will move
            
            // Run that pointer until our range is not break
            while(j+1 < n and arr[j+1] == arr[j] + 1) {
                j++;
            }
            
            // if j > i, that means we got our range more than one element
            if(j > i) {
                // Store in in range format (i.e a->b)
                temp += to_string(arr[i]); 
                temp += "->"; 
                temp += to_string(arr[j]);
            }
            else { // we got only one element as range
                temp += to_string(arr[i]); // then store that element in temp
            }
            
            ans.push_back(temp); 
            temp = ""; 
            i = j;      // Move i to j for a fresh start
        }
        return ans;
    }
};