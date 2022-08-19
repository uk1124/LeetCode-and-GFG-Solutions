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
    int maxLevelSum(TreeNode* root) {
        if(!root) {
            return 0;
        } 
        queue<TreeNode*> q;
        int ans_level = 0, global_sum = INT_MIN, level = 0;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            int temp_sum = 0;
            while(size--) {
                TreeNode* temp = q.front();
                q.pop();
                temp_sum += temp->val;
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
            level++;
            if (temp_sum > global_sum) {
                ans_level = level;
            }
            global_sum = max(global_sum, temp_sum);
        }
        return ans_level;
    }
};