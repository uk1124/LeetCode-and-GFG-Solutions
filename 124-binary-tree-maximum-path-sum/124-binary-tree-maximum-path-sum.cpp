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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathSum(root, maxi);
        return maxi;
    }
    
    int maxPathSum(TreeNode* root, int &maxi) {
        if(!root) {
            return 0;
        }
        
        int LeftSum = max(0, maxPathSum(root->left, maxi));     // 0 if sum comes to be -ve
        int RightSum = max(0, maxPathSum(root->right, maxi));   // 0 if sum comes to be -ve
        
        maxi = max(maxi, LeftSum + RightSum + root->val);
        return root->val + max(LeftSum, RightSum);
    }
};