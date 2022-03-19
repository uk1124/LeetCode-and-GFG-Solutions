/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *curr = head, *tempnext, *runner;
        
        while (curr) {
            if (curr->child) {
                tempnext = curr->next;
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = NULL;
                
                runner = curr->next;
                while (runner->next) {
                    runner = runner->next;
                }
                runner->next = tempnext;
                if (runner->next) {
                    runner->next->prev = runner;
                }
            }
            curr = curr->next;
        }
        
        return head;
    }
};