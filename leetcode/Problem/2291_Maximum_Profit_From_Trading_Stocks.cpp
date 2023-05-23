class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int n = present.size();

        vector<vector<int>> profits(n, vector<int>(2,0));
        for (int i=0; i<n; i++) {
            profits[i] = {present[i], future[i]-present[i]};
        }

        vector<int> dp(budget+1, 0);
        vector<int> prev_dp(budget+1, 0);

        for (int i=0; i<n; i++) {
            int cost = profits[i][0];
            int profit = profits[i][1];
            for (int j=cost; j<=budget; j++) {
                dp[j] = max(prev_dp[j], prev_dp[j-cost]+profit);
            } 
            prev_dp = dp;
        }

        return dp[budget];

    }
};
