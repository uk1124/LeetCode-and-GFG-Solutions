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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        while(temp1 != NULL) {
            temp1 = temp1->next;
            length++;
        }
        if(length == n) {
            return head->next;
        }
        int pos = length-n;
        int curr = 1;
        while(curr++ != pos) {
            temp2 = temp2->next;
        }
        temp2->next = temp2->next->next;
        return head;
    }
};