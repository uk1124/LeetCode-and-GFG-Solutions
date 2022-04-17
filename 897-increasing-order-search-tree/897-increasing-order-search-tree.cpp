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
    TreeNode* increasingBst(TreeNode* root, TreeNode* tail = NULL) {
        if(!root) {
            return tail;
        }
        TreeNode *node = increasingBst(root->left, root);
        
        root->left = NULL;
        root->right = increasingBst(root->right, tail);
        
        return node;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        return increasingBst(root, NULL);
    }
};