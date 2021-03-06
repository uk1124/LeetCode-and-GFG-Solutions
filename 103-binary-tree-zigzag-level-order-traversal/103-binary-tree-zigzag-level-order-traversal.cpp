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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;    // It will help to decide the order of zig-zag traversal
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> v(size);
            
            for(int i=0; i<size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                int index;
                if(leftToRight) {
                    index = i;
                }
                else {
                    index = size - i - 1;
                }
                v[index] = temp->val;
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
            leftToRight = !leftToRight;
            ans.push_back(v);
        }
        return ans;
    }
};