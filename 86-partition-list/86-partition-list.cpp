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
    // APPROACH: Create separate linked lists for the front and back portions of list we want to return
    ListNode* partition(ListNode* head, int x) {
        ListNode *head1 = new ListNode(0);
        ListNode *head2 = new ListNode(0);
        ListNode *h1 = head1, *h2 = head2;
        
        while(head) {
            int t = head->val;
            if(t < x) {             // For nodes having value less than x
                head1->next = head;
                head1 = head1->next;
            } 
            else {                  // For nodes having value greater than x
                head2->next = head;
                head2 = head2->next;
            }
            head = head->next;
        }
        head2->next = NULL;
        head1->next = h2->next;;
        return h1->next;
    }
};