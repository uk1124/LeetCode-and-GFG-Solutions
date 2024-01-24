/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 /*APPROACH:
- Use a depth-first traversal to explore paths from the root to leaves in a binary tree, maintaining a count of occurrences for each digit. 
- After reaching a leaf, check if the path is pseudo-palindromic (at most one digit with an odd count), incrementing a global count if true. The final count represents the required answer.
 */
class Solution {
private:
    unordered_map<int, int> mp;
public:
    void traverse(TreeNode *root, int &count) {
        if(!root) {
            return;
        }
        // Increment the count of the current digit in the path
        mp[root->val]++;

        // If it's a leaf node, check if it's a pseudo-palindromic path
        if(!root->left and !root->right) {
            // Count the number of digits with odd occurrences
            int oddCount = 0;
            for(const auto &entry : mp) {
                if (entry.second % 2 != 0) {
                    oddCount++;
                }
            }
            // If at most one digit has an odd count, it's pseudo-palindromic
            if(oddCount <= 1) {
                count++;
            }
        }

        // Recur for left and right subtrees
        traverse(root->left, count);
        traverse(root->right, count);

        // Decrement the count of the current digit after the subtree is processed
        mp[root->val]--;
    }

    int pseudoPalindromicPaths(TreeNode *root) {
        int count = 0;
        traverse(root, count);
        return count;
    }
};