class Solution {
public:
    double solve(vector<vector<double>>& dp, vector<vector<double>>& avg, int n, int i, int k) {
        if (dp[i][k] != -1) return dp[i][k];
        if (k==1) return dp[i][k] = avg[i][n-1];

        for (int j=i+1; j<=(n-k+1); j++) {
            dp[i][k] = max(dp[i][k], avg[i][j-1] + solve(dp, avg, n, j, k-1));
        }
        
        return dp[i][k];
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<double>> dp(n, vector<double>(k+1, -1));

        vector<double> prefix(n+1, 0);
        vector<vector<double>> avg(n, vector<double>(n, 0));

        for (int i=1; i<=n; i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }

        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                avg[i][j] = (prefix[j+1] - prefix[i])/(j-i+1);
            }
        }

        return solve(dp, avg, n, 0, k);
    }
};
