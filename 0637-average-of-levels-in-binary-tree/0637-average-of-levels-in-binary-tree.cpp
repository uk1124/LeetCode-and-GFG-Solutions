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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root)
            return {};  // Return an empty vector if the root is null.

        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int levelSize = q.size();  // Number of nodes at the current level.
            double levelSum = 0;

            for(int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                levelSum += node->val;

                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            
            double levelAvg = levelSum / levelSize;
            ans.push_back(levelAvg);
        }

        return ans;
    }
};