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
    TreeNode* findMin(TreeNode* node) {
       while(node->left) {
        node = node->left;
    }
        return node;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp;
        if(!root) {
            return NULL;
        }
        else if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if(!root->left){        // Node only has right subtree, return the right subtree
                return root->right;
            }
            else if(!root->right){  // Node only has left subtree, return the left subtree
                return root->left;
            }
                                    // Node has both left and right subtree
                temp = findMin(root->right); // Find the minimum value in the right subtree
                root->val = temp->val;       // Set that value to the currently found node
                                                             
        root->right = deleteNode(root->right, root->val); // Recursively delete the minimum
                                                          // value in the right subtree
        }
        return root;
    }
};