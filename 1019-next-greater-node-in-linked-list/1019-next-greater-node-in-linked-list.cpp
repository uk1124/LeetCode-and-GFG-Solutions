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
    //APPROACH: Push list values into a vector and then same as 'Next greater element in an array'.
    vector<int> nextLargerNodes(ListNode* head) {
        vector <int> values;
        while(head) {
            values.push_back(head->val);
            head = head->next;
        }
        
        int n = values.size();
        stack <int> st;
        vector <int> ans(n);
        for(int i = 0; i<n; i++) {
            while (!st.empty() and values[i] > values[st.top()]) {
                ans[st.top()] = values[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};