class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), 
            [](vector<int>& a, vector<int>& b) {
                if (a[1]==b[1]) return a[0]<b[0];
                else return a[1]<b[1];
            });

        int rst = 1;
        int n = points.size();
        int max_x = points[0][1];
        for (int i=1; i<n; i++) {
            if (points[i][0] > max_x) {
                rst++;
                max_x = points[i][1];
            }
        }

        return rst;
    }
};
