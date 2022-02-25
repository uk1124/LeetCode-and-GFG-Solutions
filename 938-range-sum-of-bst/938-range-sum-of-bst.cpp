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
public:                     // RECURSIVE SOLUTION
    // int sum = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
//         if(!root) {
//             return 0;
//         }
        
//         if(root->val >= low and root->val <= high) {
//             sum += root->val;
//         }
//         if(root->val > low) {                  // Left child is possible candidate
//             rangeSumBST(root->left, low, high);
//         }
//         if(root->val < high) {                 // Right child is possible candidate
//             rangeSumBST(root->right, low, high);
//         }
//         return sum;
        
        
                        // ITERATIVE SOLUTION
        stack <TreeNode*> st;
        st.push(root);
        int sum = 0;
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (!node) { 
                continue; 
            }
            if(node->val >= low and node->val <= high) {
                sum += node->val;
            }
            if (node->val > low) {             // Left child is possible candidate
                st.push(node->left); 
            } 
            if (node->val < high) { 
                st.push(node->right);          // Right child is possible candidate
            } 
        }
        return sum;
    }
};