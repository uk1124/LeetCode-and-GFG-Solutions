class Solution {
public:
/*APPROACH:
Use a stack to simulate asteroid collisions. Iterate through the asteroids, compare their sizes and 
directions with those on the stack to determine collisions. If a collision occurs, the smaller 
asteroid(s) explode, leaving only the surviving asteroids in the stack as the final result.
*/
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;  // Stack to track asteroids during collision
        
        for(int i = 0; i < asteroids.size(); i++) {
            int curr = asteroids[i];    // Get the current asteroid
            
            // If the stack is not empty and current asteroid is moving left (negative)
            while(!st.empty() and st.top() > 0 and curr < 0) {
                // Check for collision
                if(abs(st.top()) == abs(curr)) {
                    // If the absolute values of the asteroids are equal, both asteroids explode
                    st.pop();
                    curr = 0; // Mark current asteroid as exploded
                    break;    // No need to check further
                } 
                else if(abs(st.top()) < abs(curr)) {
                    // If the current asteroid is larger than the top asteroid in the stack, the top asteroid is destroyed
                    st.pop();
                } 
                else {
                    // If the current asteroid is smaller than the top asteroid in the stack, the current asteroid is destroyed
                    curr = 0; // Mark current asteroid as exploded
                    break;    // No need to check further
                }
            }
            // If current asteroid is not exploded, push it to the stack
            if(curr != 0)
                st.push(curr);
        }
        
        // Convert remaining asteroids in stack to vector
        vector<int> ans(st.size());
        for(int i = st.size()-1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        
        return ans;
    }
};
