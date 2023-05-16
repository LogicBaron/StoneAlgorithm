class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        if (target<n) return 0;
        if (target==n) return 1;

        vector<vector<long long>> dp(n+1, vector<long long>(target+1, 0));
        long long mod = 1000000007;

        for (int i=1; i<=min(k, target); i++) {
            dp[1][i] = 1;
        }

        for (int i=2; i<=n; i++) {
            for (int j=i; j<=min(i*k, target); j++) {
                for (int l=1; l<=min(j-1, k); l++) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-l]) % mod;
                }
            }
        }

        return dp[n][target];
    }
};
