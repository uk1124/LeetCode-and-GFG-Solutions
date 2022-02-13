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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return NULL;
        }
        TreeNode* root = makeBST(nums, 0, n-1);
        return root;
    }
    
    TreeNode* makeBST(vector<int> &v, int lo, int hi) {
        if(lo > hi) {
            return NULL;
        }
        int mid = (lo + hi) / 2;
        TreeNode* node = new TreeNode(v[mid]);
        node->left = makeBST(v, lo, mid-1);
        node->right = makeBST(v, mid+1, hi);
        return node;
    }
};