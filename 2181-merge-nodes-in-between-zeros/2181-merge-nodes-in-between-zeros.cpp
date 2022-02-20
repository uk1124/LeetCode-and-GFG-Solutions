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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *p1 = head, *p2 = head->next;
        while(p2) {
            p1->val += p2->val;          
            if(p2->val == 0) {          
                p1->next = p2;           
                p1 = p1->next;
            }
            p2 = p2->next;
        }
        ListNode *temp = head;
        while(temp->next->next) {           // For removing the last node (which contains 0)
            temp = temp->next;
        }
        temp->next = NULL;
        return head;
    }
};