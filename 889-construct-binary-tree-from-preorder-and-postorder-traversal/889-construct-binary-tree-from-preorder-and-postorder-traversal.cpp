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
// APPROACH: As root node would be lastly traversed in postorder, so if root->val == postorder[postIndex] it means we have contructed the tree, else recursively contruct left and right subtree
    int preIndex = 0, postIndex = 0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        
        if(root->val != postorder[postIndex]) {
            root->left = constructFromPrePost(preorder, postorder);
        }
         if(root->val != postorder[postIndex]) {
            root->right = constructFromPrePost(preorder, postorder);
        }
        postIndex++;
        
        return root;
    }
};