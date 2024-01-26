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
/*APPROACH: Perform an in-order traversal of the BST and calculate the min absolute difference between consecutive node values. The min difference is updated during traversal, resulting in the overall min absolute difference between any two nodes in the tree.
*/
private:
    // Variables to store the min absolute difference and previous node's value during traversal
    int ans = INT_MAX;
    int prev = INT_MAX;
public:
    // DFS function to traverse the BST
    void dfs(TreeNode *root) {
        // Traverse the left subtree if it exists
        if (root->left) {
            dfs(root->left);
        }

        // Calculate the absolute diff between the current node's value & the previous node's value
        ans = min(ans, abs(root->val - prev));
        // Update the previous node's value
        prev = root->val;

        // Traverse the right subtree if it exists
        if (root->right) {
            dfs(root->right);
        }
    }

    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
