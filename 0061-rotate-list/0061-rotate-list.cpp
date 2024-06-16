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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        // Compute the size of the linked list
        int size = 0;
        ListNode* temp = head;
        while (temp) {
            size++;
            temp = temp->next;
        }

        // Compute the effective rotations needed
        k = k % size;
        if (k == 0) {
            return head;
        }

        // Find the new tail: (size - k - 1)th node and the new head: (size - k)th node
        ListNode* newTail = head;
        for (int i = 0; i < size - k - 1; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;

        // Break the link to form the new list
        newTail->next = nullptr;

        // Find the old tail and connect it to the old head
        ListNode* oldTail = newHead;
        while (oldTail->next) {
            oldTail = oldTail->next;
        }
        oldTail->next = head;

        return newHead;
    }
};