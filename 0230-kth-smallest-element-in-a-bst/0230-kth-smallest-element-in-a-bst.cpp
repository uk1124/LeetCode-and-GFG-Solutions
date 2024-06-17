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
//APPROACH: Inorder traversal of BST produces sorted list, so while traversing keep track of the no. of elements visited 
    
    int count = 0;  // Counter to keep track of the number of nodes visited

    int kthSmallest(TreeNode* root, int k) {
        // If the root is null, return 0
        if (!root) {
            return 0;
        }
        // Find the kth smallest node
        TreeNode* node = kthSmallestNode(root, k);
        return node->val;  // Return the value of the kth smallest node
    }
    
    // Helper function to find the kth smallest node in the BST
    TreeNode* kthSmallestNode(TreeNode* root, int k) {
        // If the root is null, return null
        if (!root) {
            return nullptr;
        }
        
        // Recursively traverse the left subtree
        TreeNode* left = kthSmallestNode(root->left, k);
        
        // If the kth smallest node is found in the left subtree, return it
        if (left) {
            return left;
        }
        // Increment the counter and check if the current node is the kth smallest
        if (++count == k) {
            return root;
        }
        
        // Recursively traverse the right subtree
        return kthSmallestNode(root->right, k);
    }
};
