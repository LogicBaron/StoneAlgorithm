class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        map<int, vector<vector<int>>> mp;

        for (vector<int> ride: rides) {
            mp[ride[1]].push_back({ride[0], ride[2]});
        }

        vector<long long> dp(n+1, 0);
        for (int i=1; i<=n; i++) {
            dp[i] = dp[i-1];
            for (vector<int> ride: mp[i]) {
                dp[i] = max(dp[i], dp[ride[0]]+(i-ride[0]+ride[1]));
            }
        }

        return dp[n];
    }
};
