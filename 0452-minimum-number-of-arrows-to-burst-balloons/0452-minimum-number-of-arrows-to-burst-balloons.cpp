class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int ans = 0;
        for(int i=0; i<points.size(); i++) {
            if(i < points.size()-1 and points[i][1] >= points[i+1][0]) {
                cout<<points[i][0]<<" "<<points[i][1]<<endl;
                ans++;
                i++;
            }
            else {
                ans++;
            }
        }
        return ans;
    }
};