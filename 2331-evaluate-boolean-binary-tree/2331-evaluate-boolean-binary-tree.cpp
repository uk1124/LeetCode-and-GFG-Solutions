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
class Solution {
public:
  bool solve(TreeNode* root) {
    // Base cases: Leaf node with value 0 (False) or 1 (True)
    if (root->val == 0 or root->val == 1) {
      return root->val == 1; // Return True only for leaf node with value 1
    } 
    // Non-leaf node with value 2 (OR operation)
    else if (root->val == 2) {
      return solve(root->left) or solve(root->right); // Evaluate OR using left and right children
    } 
    // Non-leaf node with value 3 (AND operation)
    else if (root->val == 3) {
      return solve(root->left) and solve(root->right); // Evaluate AND using left and right children
    } 
    // Invalid node value
    else {
      return false; // Handle error (optional)
    }
  }

  bool evaluateTree(TreeNode* root) {
    // Call the recursive function 'solve' to start evaluation from the root
    return solve(root);
  }
};
