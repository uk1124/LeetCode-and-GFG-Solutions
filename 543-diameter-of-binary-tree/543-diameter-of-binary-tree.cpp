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
    int diameterOfBinaryTree(TreeNode* root) {      // TC: O(N)
        int diameter = 0;
        heightOfTree(root, diameter);
        return diameter;
    }
    
    int heightOfTree(TreeNode* node, int &diameter) {
        if(node == NULL) {
            return 0;
        }
        
        int leftHeight = heightOfTree(node->left, diameter);
        int rightHeight = heightOfTree(node->right, diameter);
        
        diameter = max(diameter, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
};