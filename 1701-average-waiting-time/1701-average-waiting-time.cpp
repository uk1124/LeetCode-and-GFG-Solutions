class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
/*1 -> 2 .. 1, 2,3
2-> 5, 4,5,6,7,8
3-> 4, 9,10,11
*/
    long long ans = 0;
    int current_time = 0;

    for(auto v: customers) {
        int arrival_time = v[0];
        int cooking_time = v[1];

        if(arrival_time > current_time) {
            current_time = arrival_time;
        }

        int waiting_time = current_time - arrival_time + cooking_time;
        ans += waiting_time;

        current_time += cooking_time;
    }

    return (double)ans/customers.size();

    }
};