class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int ans;
        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(), [](vector<int> a, vector<int> b) {
            if (a[0] == b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });

        vector<int> dp;

        dp.push_back(INT_MIN);
        for (int i=0; i<n; i++) {
            if (dp.back() < envelopes[i][1]) {
                dp.push_back(envelopes[i][1]);
            }
            else {
                auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
                *it = envelopes[i][1];
            }
        }

        return dp.size()-1;
    }
};
