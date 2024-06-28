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
    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
    
    bool isBST(TreeNode* node, long mini, long maxi) {
        if(!node) {
            return true;
        }
        if(node->val >= maxi or node->val <= mini) {
            return false;
        }
        // Each node value has to be in between a range according to the property of BST
        return isBST(node->left, mini, node->val) and isBST(node->right, node->val, maxi);
    }
};