// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    Node * p = new Node(-1);
    Node *plast = p;
    Node *q = new Node(-1);
    Node *qlast = q;
    Node *r = new Node(-1);
    Node *rlast = r;
    Node *curr = head;
   
   while(curr) {
       if(curr->data<x) {
           plast->next = curr;
           plast = plast->next;
       }
       else if(curr->data == x) {
           qlast->next = curr;
           qlast = qlast->next;
           
       }
       else {
           rlast->next = curr;
           rlast = rlast->next;
           
       }
       curr = curr->next;
   }
   
   rlast->next = NULL;
   qlast->next = r->next;
   plast->next = q->next;
   return p->next;
}