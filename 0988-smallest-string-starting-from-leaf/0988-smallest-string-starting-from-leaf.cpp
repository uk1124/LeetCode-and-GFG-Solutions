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
    // Recursive function to traverse the tree and build the smallest string
    string dfs(TreeNode* root, string path) {
        // Append the current node's character to the path
        path = char('a' + root->val) + path;
        
        // Check if the current node is a leaf node (If it is, return the path)
        if(!root->left and !root->right) {
            return path;
        }
        
        // If the left child exists, recursively traverse the left subtree
        string leftPath = (root->left) ? dfs(root->left, path) : "";
        
        // If the right child exists, recursively traverse the right subtree
        string rightPath = (root->right) ? dfs(root->right, path) : "";
        
        // Return the lexicographically smaller path among the paths from left and right subtrees
        if(leftPath.empty()) {
            return rightPath;
        } 
        else if(rightPath.empty()) {
            return leftPath;
        } 
        else {
            // If both paths are not empty, return the smaller one
            return min(leftPath, rightPath);
        }
    }

    string smallestFromLeaf(TreeNode* root) {
        // Edge case: if root is null, return an empty string
        if(!root) {
            return "";
        }
        // Start recursive traversal from root with an empty path
        return dfs(root, "");
    }
};