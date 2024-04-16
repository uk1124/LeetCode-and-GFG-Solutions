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
// Approach: Using DFS
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // If the root is null, return null
        if(!root) {
            return root;
        }
        
        // Edge case: if depth is 1, create a new root node with the given value
        if(depth == 1) {
            return new TreeNode(val, root, nullptr);
        }
        
        // If depth is 2, add new nodes as the left and right children of the current root
        if(depth == 2) {
            root->left = new TreeNode(val, root->left, nullptr);
            root->right = new TreeNode(val, nullptr, root->right);
            return root;
        }
        
        // Recursively traverse the left and right subtrees with depth decremented by 1
        addOneRow(root->left, val, depth - 1);
        addOneRow(root->right, val, depth - 1);
        
        return root;
    }
};