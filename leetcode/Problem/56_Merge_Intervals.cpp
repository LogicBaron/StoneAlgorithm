class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        int low = intervals[0][0], high = intervals[0][1];

        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i][0] <= high) {
                high = max(high, intervals[i][1]);
            }
            else {
                ans.push_back({low, high});
                low = intervals[i][0];
                high = intervals[i][1];
            }
        }
        ans.push_back({low, high});

        return ans;
    }
};
