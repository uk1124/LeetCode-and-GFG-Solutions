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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL and q == NULL) {  // If both trees are NULL
            return true;
        }
        if(p == NULL or q == NULL) {   // If any one tree is NULL and not other
            return false;
        }
        
        if(p->val == q->val) {// If both trees are not NULL, check for left & right subtrees
            return isSameTree(p->left, q->left) and isSameTree(p->right,q->right);
        }
        return false;
    }
};