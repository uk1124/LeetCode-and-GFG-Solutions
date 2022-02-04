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
    
    bool isBalanced(TreeNode* root) {   // TC: O(N)
        return height(root) != -1;
    }
    
    int height(TreeNode* root) {        // For finding height and checking if it's balanced
        if(root == NULL) {
            return 0;
        }
        int leftHeight = height(root->left);
        if(leftHeight == -1) {
            return -1;
        }
        int rightHeight = height(root->right);
        if(rightHeight == -1) {
            return -1;
        }
        
        if(abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return max(leftHeight, rightHeight) + 1;
    }
};