class Solution {
public:
    /*APPROACH:Two pointer approach
    Sorting the array of string products by increasing lexigographically order
    Using two pointer startIndex and endIndex to filter products that match characters with their positions so far
    Collect nearest 3 products in range [startIndex, endIndex].*/
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        sort(products.begin(), products.end());     //Sort by increasing lexicographically order of products
        vector<vector<string>> ans;
        int startIdx = 0, endIdx = n-1;
        
        for(int i = 0; i < searchWord.length(); i++) {
            while(startIdx <=endIdx and (i >= products[startIdx].size() or products[startIdx][i] < searchWord[i])) {
                startIdx++;
            }
            while(startIdx <= endIdx and (i >= products[endIdx].size() or products[endIdx][i] > searchWord[i])) {
                endIdx--;
            }

            ans.push_back({});
            for(int j = startIdx; j < min(startIdx+3, endIdx+1); ++j) {
                ans.back().push_back(products[j]);
            }
        }
        return ans;
    }
};