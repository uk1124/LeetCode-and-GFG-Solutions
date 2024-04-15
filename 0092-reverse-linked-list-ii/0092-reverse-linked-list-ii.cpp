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
        // Check if the list is empty or has only one node
        if (head == nullptr or head->next == nullptr) {
            return head;
        }
        
        // Create a dummy node to handle cases where left is at the beginning of the list
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        // Initialize pointers for the previous and current nodes
        ListNode *prev = dummy, *curr = head;
        
        // Move the 'prev' pointer to the node just before the 'left' node
        for (int i = 1; i < left; i++) {
            prev = prev->next;
            curr = curr->next;
        }
        
        // Reverse the sublist from 'left' to 'right'
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
        }
        
        // Return the modified list
        return dummy->next;
    }
};
