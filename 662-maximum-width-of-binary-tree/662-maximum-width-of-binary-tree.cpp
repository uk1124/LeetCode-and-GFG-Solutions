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

/*  APPROACH: Using Level Order Traversal. 
    
    Regardless whether these nodes exist:
    -> Always make the id of left child as parent_id * 2;
    -> Always make the id of right child as parent_id * 2 + 1;
    
    At each node, compare the distance from it the left most node with the current max width
*/

class Solution {
public:        
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        unsigned long long maxi = 0;
        queue <pair<TreeNode*, unsigned long long>> q;
        q.push(pair<TreeNode*, unsigned long long>(root, 1));
        
        while (!q.empty()) {
            unsigned long long l = q.front().second, r = l;     // Right started same as left
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front().first;
                r = q.front().second;
                q.pop();
                if (node->left) {
                    q.push({node->left, r * 2});
                }
                if (node->right) {
                    q.push({node->right, r * 2 + 1});
                }
            }
            maxi = max(maxi, r + 1 - l);
        }
        return maxi;
    }
};