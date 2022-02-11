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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *p1, *p2 = head;
        ListNode *temp = head;
        while(--k) {
            temp = temp->next;
        }
        p1 = temp;              // p1 would be at the first node which needs to be swapped
        temp = temp->next;
        while(temp) {
            p2 = p2->next;
            temp = temp->next;
        }                       // p2 would be at the second node which needs to be swapped
        swap(p1->val, p2->val);
        return head;
    }
};