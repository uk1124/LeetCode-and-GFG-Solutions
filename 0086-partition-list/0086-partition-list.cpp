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
    //APPROACH: Create separate linked lists for the front and back portions of list we want to return
    ListNode* partition(ListNode* head, int x) {
        // Create dummy nodes for the front and back portions of the partitioned list
        ListNode *front = new ListNode(0);  // Stores nodes with values less than x
        ListNode *back = new ListNode(0);   // Stores nodes with values greater than or equal to x
        ListNode *frontPtr = front, *backPtr = back; // Pointers to traverse front and back lists
        
        // Traverse the original list
        while(head) {
            int val = head->val;
            if(val < x) {
                // Append the node to the front list if its value is less than x
                frontPtr->next = head;
                frontPtr = frontPtr->next;
            } else {
                // Append the node to the back list if its value is greater than or equal to x
                backPtr->next = head;
                backPtr = backPtr->next;
            }
            head = head->next;
        }
        
        // Terminate the back list and link the front list to it
        backPtr->next = nullptr;
        frontPtr->next = back->next;
        
        // Return the head of the front list (excluding the dummy node)
        return front->next;
    }
};
