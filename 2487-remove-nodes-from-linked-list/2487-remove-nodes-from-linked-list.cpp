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
    // Function to check if there is a greater node to the right of the current node
    bool hasGreaterNode(ListNode* node) {
        int val = node->val;         // Value of the current node
        ListNode* curr = node->next; // Pointer to the next node
        while(curr) {
            if(curr->val > val) { // If a greater node is found
                return true;
            }
            curr = curr->next;   // Move to the next node
        }
        return false; // No greater node found
    }

    ListNode* removeNodes(ListNode* head) {
        if (!head or !head->next) { // If the list is empty or has only one node
            return head; // Return the list as is
        }
        
        ListNode* dummy = new ListNode(-1); // Dummy node to handle edge cases
        dummy->next = head;     // Link the dummy node to the head of the list
        ListNode* curr = dummy; // Pointer to traverse the list
        
        while(curr->next and curr->next->next) {  // Iterate through the list
            if(hasGreaterNode(curr->next)) {      // If the current node should be removed
                curr->next = curr->next->next;    // Skip the current node by adjusting pointers
            } 
            else {
                curr = curr->next; // Move to the next node
            }
        }
        
        return dummy->next;       // Return the modified list
    }
};
