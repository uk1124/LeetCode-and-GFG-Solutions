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
private: 
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last; 
private: 
    void inorder(TreeNode* root) {
        if(!root) {
            return; 
        }
        
        inorder(root->left);                                 // Left call
        
        if (prev != NULL and (root->val < prev->val)) {      // Doing the business
           
            // If this is first violation, mark these two nodes as 'first' and 'middle'
            if (first == NULL) {
                first = prev;
                middle = root;
            }
 
            // If this is second violation, mark this node as last
            else {
                last = root;
            }
        }
 
        // Mark this node as previous
        prev = root;
        
        inorder(root->right);                                // Right call
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL; 
        prev = new TreeNode(INT_MIN); 
        inorder(root);
        
        if(first and last) {
            swap(first->val, last->val); 
        }
        else if(first and middle) {
            swap(first->val, middle->val); 
        }
    }
};