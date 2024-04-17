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
    string dfs(TreeNode* root, string path) {
        // Append the current node's character to the path
        path = char('a' + root->val) + path;
        
        // Check if the current node is a leaf node (i.e., it has no children)
        if (!root->left and !root->right) {
            // If it's a leaf node, return the path (this is a candidate string)
            return path;
        }
        
        // If the left child exists, recursively traverse the left subtree
        string leftPath = (root->left) ? dfs(root->left, path) : "";
        
        // If the right child exists, recursively traverse the right subtree
        string rightPath = (root->right) ? dfs(root->right, path) : "";
        
        // Return the lexicographically smaller path among the paths from left and right subtrees
        if (leftPath.empty()) {
            return rightPath;
        } 
        else if (rightPath.empty()) {
            return leftPath;
        } 
        else {
            return min(leftPath, rightPath);
        }
    }

    string smallestFromLeaf(TreeNode* root) {
        // Edge case: if root is null, return an empty string
        if (!root) {
            return "";
        }
        // Recursively traverse the tree and build the lexicographically smallest string
        return dfs(root, "");
    }
};