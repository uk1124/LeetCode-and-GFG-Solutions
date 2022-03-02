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
    // APPROACH: For each node during pre-order traversal of root, use a recursive function isIdentical to validate if sub-tree started with this node is the same with subRoot
    bool isIdentical(TreeNode* root, TreeNode* subRoot) {
        if (!root and !subRoot) {
            return true;
        }
        if (!root or !subRoot) {
            return false;
        }
        
        if (root->val != subRoot->val) {
            return false;
        }
        
        return isIdentical(root->left, subRoot->left) and isIdentical(root->right, subRoot->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        if (isIdentical(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};