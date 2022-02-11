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
    bool isSymmetric(TreeNode* root) {
        if(!root) {
            return true;
        }
        return Symmetric(root->left, root->right);
    }
    
    bool Symmetric(TreeNode* left, TreeNode* right) {
        if(!left or !right) {
            return (left == right);
        }
        if(left->val != right->val) {
            return false;
        } 
        // Apart from the orientation, the values of the nodes should also be equal
        return Symmetric(left->left, right->right) and Symmetric(left->right, right->left);
    }
};