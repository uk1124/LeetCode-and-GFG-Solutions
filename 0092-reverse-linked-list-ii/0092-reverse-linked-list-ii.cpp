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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL and head->next == NULL) {
            return head;
        }
        //ListNode *dummy = new ListNode(0);
        //ListNode *prev = dummy;
        ListNode *prev = head;
        ListNode *curr;
        //dummy->next = head;
        int i = 2;
        while(i++ < left) {
           prev = prev->next;
        }                               // prev is at the node just before the 'left' one
        curr = prev->next;
        for (int i = 0; i < right-left; i++) {
            ListNode* temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
        }
       // return dummy->next;
       return head;
    }
};