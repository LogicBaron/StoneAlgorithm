class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, 0));

        dp[0][1] = 1;

        for (int i=1; i<n; i++) {
            if (nums[i] > nums[i-1]) {
                dp[i][0] = dp[i-1][0] + dp[i-1][1];
                dp[i][1] = dp[i-1][1] +1;
            }
            else {
                dp[i][0] = dp[i-1][0] + dp[i-1][1];
                dp[i][1] = 1;
            }
        }

        return dp[n-1][0] + dp[n-1][1];
    }
};
