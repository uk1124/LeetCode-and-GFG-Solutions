/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head or !head->next) {
            return NULL;
        }
        ListNode *fast = head, *slow = head;
        ListNode *temp = head;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                while(slow != temp) {
                    slow = slow->next;
                    temp = temp->next;
                }
                return temp;
            }
        }
        return NULL;
    }
};