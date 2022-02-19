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
    // Main logic: Depth of the nodes should be same but their parent should not be the same
     TreeNode* get_depth(TreeNode* root, int data, int depth, int &level) {
        if(!root) {
            return NULL;
        }
         if(root->left and root->left->val==data or root->right and root->right->val==data) {
           level = depth;
           return root;
        }
         
        TreeNode* left = get_depth(root->left, data, depth + 1, level);
        TreeNode* right = get_depth(root->right, data, depth + 1, level);
        
         return left ? left : right;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        int depthX = -1, depthY = -1;       // As depth of root = 0, so it's parent depth = -1
        TreeNode *parentX, *parentY;
        
        parentX = get_depth(root, x, 0, depthX);
        parentY = get_depth(root, y, 0, depthY);
            
        if(depthX == depthY and parentX != parentY) {
            return true;
        }
        return false;
    }
};