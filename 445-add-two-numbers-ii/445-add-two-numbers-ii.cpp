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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int size1 = 0, size2 = 0, carry = 0;
        ListNode *curr1 = l1, *curr2 = l2, *res = NULL;
        while(curr1) {
            curr1 = curr1->next;
            size1++;
        }
         while(curr2) {
            curr2 = curr2->next;
            size2++;
        }
        curr1 = l1, curr2 = l2;
        while(size1 > 0 and size2 > 0) {
            int sum = 0;
            if(size1 >= size2) { 
                sum += curr1->val; 
                curr1 = curr1->next;
                size1--;
            }
            if(size2 > size1) {
                sum += curr2->val; 
                curr2 = curr2->next;
                size2--;
            }
            ListNode* temp = new ListNode(sum);
            temp->next = res;
            res = temp;
        }
        curr1 = res;
        res = NULL;
        while(curr1) {
            curr1->val += carry; 
            carry = curr1->val / 10;

            ListNode* temp = new ListNode(curr1->val % 10);
            temp->next = res;
            res = temp;
            
            curr2 = curr1; 
            curr1 = curr1->next;
        }
        if(carry) {
            ListNode* temp = new ListNode(1);
            temp->next = res;
            res = temp;
        }
        return res;
    }
};