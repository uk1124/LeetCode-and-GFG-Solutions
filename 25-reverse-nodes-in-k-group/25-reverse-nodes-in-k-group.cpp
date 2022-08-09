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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        for(int i = 0; i < k; i++){
            if(!node) {
                return head;
            }
            node = node->next;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt;
        for(int i = 0; i < k; i++) {            // Same logic as of reverse a LL
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};