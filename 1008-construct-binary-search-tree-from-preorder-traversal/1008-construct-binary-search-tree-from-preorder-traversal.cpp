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
    /*APPROACH: Add all the values which has value less than root (v[0]) to the 'left' vector and the values which
    has value greater than root (v[0]) to the 'right' vector
    Then Recursively call the function for left and right subtree. */
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[0]);     //Root of the would be the first element of the array
        if(preorder.size() == 1) {
            return root;
        }
        vector<int> left;
        vector<int> right;
        for(int i=0; i<preorder.size(); i++) {
            if(preorder[i] > preorder[0]) {
                right.push_back(preorder[i]);
            }
            else if(preorder[i] < preorder[0]) {
                left.push_back(preorder[i]);
            }
        }
        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);
        return root;
        
    }
};