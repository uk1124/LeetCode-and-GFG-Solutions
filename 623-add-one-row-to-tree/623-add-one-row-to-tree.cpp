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
    //APPROACH: Using DFS
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) {
            return root;
        }
        if(depth == 1) {           //Edge case: d == 1
            return new TreeNode(val, root, NULL);
        }
        if(depth == 2) {           //Right depth reached!
            root->left = new TreeNode(val, root->left, NULL);
            root->right = new TreeNode(val, NULL, root->right);
            return root;
        }
        
        addOneRow(root->left, val, depth - 1);
        addOneRow(root->right, val, depth - 1);
        return root;
    }
};