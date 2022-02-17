// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) 
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

 // } Driver Code Ends
//User function Template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution{
    /*
    Here state of a node can be {-1, 0, 1}
    state -1 = need vaccine;
    state 0 = vaccinated;
    state 1 = has extra vaccine;
    */
private:
    int res;
    
    void countVaccine(Node* root, unordered_map<Node*, int>& state) {
        if(!root) {
            return;
        }
        
        countVaccine(root->left, state);
        countVaccine(root->right, state);
        if(state[root->left] == -1 or state[root->right] == -1) {
            state[root] = 1;
            res++;
        }
        else if(state[root->left] == 1 or state[root->right] == 1) {
            state[root] = 0;
        }
        else {
            state[root] = -1;
        }
    }
    
public:
    int supplyVaccine(Node* root){
        unordered_map<Node*, int> state;
        res = 0;
        countVaccine(root, state);
        if(state[root] == -1) {
            res++;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() 
{
    int t;
    scanf("%d ", &t);
    while (t--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout<<ob.supplyVaccine(root)<<"\n";
    }
    return 0;
}



  // } Driver Code Ends