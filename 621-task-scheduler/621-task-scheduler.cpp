class Solution {
public:
    /*APPROACH: Using Priority queue.
    - To work on the same task again, CPU has to wait for time n, therefore think of as if there is a cycle of time
    n+1, regardless whether we schedule some other task in the cycle or not.
    - To avoid leave the CPU with limited choice of tasks and having to sit there cooling down frequently at the
    end, it is critical the keep the diversity of the task pool for as long as possible.
    - In order to do that, we should try to schedule the CPU to always try round robin between the most popular
    tasks at any time.*/
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for(char t: tasks) {
            counts[t]++;
        }
        priority_queue<int> pq;
        for(auto it: counts) {
            pq.push(it.second);
        }
        
        int alltime = 0;
        int cycle = n+1;
        while (!pq.empty()) {
            int time = 0;
            vector<int> tmp;
            for(int i=0; i<cycle; i++) {
                if(!pq.empty()) {
                    tmp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for(int cnt : tmp) {
                if(--cnt) {
                    pq.push(cnt);
                }
            }
            if(!pq.empty()) {
                alltime += cycle;
            }
            else {
                alltime += time;
            }
        }
        return alltime;
    }
};