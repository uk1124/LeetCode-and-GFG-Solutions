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
    set<int>S;
    void secMin(TreeNode *root) {
        if(!root) {
            return;
        }
        S.insert(root->val);
        secMin(root->left);
        secMin(root->right);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        secMin(root);
        if(S.size() > 1) {
            int x = *(++S.begin());
            return x;
        }
        return -1;
    }
};