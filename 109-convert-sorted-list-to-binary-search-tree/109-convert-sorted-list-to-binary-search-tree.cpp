/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* node;
    TreeNode* toBST(int start, int end){
	if(start > end){
		return NULL;
	}
	
	int mid = (start + end) / 2;
	TreeNode* left = toBST(start, mid - 1);
	
	TreeNode* root = new TreeNode(node->val);
	root->left = left;
	node = node->next;

	TreeNode* right = toBST(mid + 1, end);
	root->right = right;
	
	return root;
}
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) {
            return NULL;
        }
        int size = 0;
        ListNode* temp = head;
        node = head;

        while(temp) {
            temp = temp->next;
            size++;
        }
        return toBST(0, size-1);
    }
    
};