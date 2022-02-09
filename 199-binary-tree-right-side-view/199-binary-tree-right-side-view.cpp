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
    vector<int> rightSideView(TreeNode* root) {
        vector <int> ans;
        if(root == NULL) {
            return ans;
        }
        queue <TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {                     // Level order traversal
            int size = q.size();
            ans.push_back(q.front()->val);
            while(size--) {
                TreeNode* node = q.front();
                q.pop();
                if(node->right != NULL) {       // First check for right subtree
                    q.push(node->right);
                }
                if(node->left != NULL) {        // Then check for left subtree
                    q.push(node->left);
                }
            }
        }
        return ans;
    }
};