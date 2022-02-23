// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle = INT_MAX;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(s.empty()) {
               return -1;
           }
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop() {
           if(s.empty()) {
               return -1;
           }
           int y = s.top();     // take out the top element and store it
           s.pop();             
           if(y >= minEle) {    // if the top element is greater than min element simply return it
               return y;
           }
           else {
               minEle = 2*minEle - y;   // Else get the previous min element 
               return (y + minEle) / 2; // use it to find the correct value of top element
           }
       }
       
       /*push element x into the stack*/
       void push(int x) {
           if(s.empty()) {      // if stack is empty simply push the element
               s.push(x);
               minEle = x;
           }
           else if(x > minEle) { // if x is greater than or equal to current minimum simply push
               s.push(x);
           }
           else {
               s.push(2*x - minEle); // else modify the element and then push it. Remember we have to use this formulla to get back our original data while poping
               minEle = x;
           }
       }
};

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends