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
class Solution {
public:
    /*APPROACH: Check if the element is duplicate. If yes, record it and use a while loop to go to the next unique
    element. */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        int duplicate;
        
        while(curr->next and curr->next->next) {
            if(curr->next->val == curr->next->next->val) {
                duplicate = curr->next->val;
                while(curr->next && curr->next->val == duplicate) {
                    curr->next = curr->next->next;
                }
            }
            else {
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};