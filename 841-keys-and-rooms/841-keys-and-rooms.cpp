class Solution {
public:
    //APPROACH: Use an Unordered set to record the rooms visited, and a queue for BFS.
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            visited.insert(curr);
            for(int a: rooms[curr]) {
                if(visited.find(a) == visited.end()) {  // If we haven't visited the room, push it to the queue.
                    q.push(a);
                }
            }
        }
        return visited.size() == rooms.size();
    }
};