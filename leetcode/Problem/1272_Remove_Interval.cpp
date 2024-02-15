class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> rst;

        for (vector<int> interval: intervals) {
            int a, b;

            if (interval[0] < toBeRemoved[0]) {
                a = interval[0];
                b = min(interval[1], toBeRemoved[0]);
                rst.push_back({a, b});
            }

            if (toBeRemoved[1] < interval[1]) {
                a = max(interval[0], toBeRemoved[1]);
                b = interval[1];
                rst.push_back({a, b});
            }
        }

        return rst;
    }
};
