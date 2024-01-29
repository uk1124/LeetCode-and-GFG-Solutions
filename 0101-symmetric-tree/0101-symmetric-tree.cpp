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
//RECURSIVE CODE
    // Helper function to check symmetry between two nodes
    bool symmetric(TreeNode* node1, TreeNode* node2) {
        // If either node is null, they should be equal to be symmetric
        if (!node1 or !node2) {
            return (node1 == node2);
        }
        // If values are not equal, the tree is not symmetric
        if (node1->val != node2->val) {
            return false;
        }
        // Check symmetry for subtrees
        return symmetric(node1->left, node2->right) and symmetric(node1->right, node2->left);
    }

    bool isSymmetric(TreeNode* root) {
        // If the root is null, it is symmetric
        if (!root) {
            return true;
        }
        return symmetric(root->left, root->right);
    }

/*ITERATIVE CODE
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* node1 = q.front();
            q.pop();
            TreeNode* node2 = q.front();
            q.pop();

            // If both nodes are null, continue to the next pair
            if (!node1 and !node2) {
                continue;
            }
            // If one of them is null or their values are different, the tree is not symmetric
            if (!node1 or !node2 or node1->val != node2->val) {
                return false;
            }
            // Enqueue nodes in pairs for symmetry check
            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }

        // If the queue becomes empty, the tree is symmetric
        return true;
    }
*/
};