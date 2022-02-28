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
    // APPROACH: Inorder traversal of BST produces sorted list, so while traversing, keep teack of the no. of elements visited
public:
    int count = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(!root) {
            return 0;
        }
        TreeNode* node =  kthSmallestNode(root, k);
        return node->val;
    }
    
    TreeNode* kthSmallestNode(TreeNode* root, int k) {
        if(!root) {
            return NULL;
        }
        
        TreeNode* left =  kthSmallestNode(root->left, k);
        
        if(left) {
            return left;
        }
        if(++count == k) {
            return root;
        }
        return kthSmallestNode(root->right, k);
    }
};