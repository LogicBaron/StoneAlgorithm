class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix;
        prefix.push_back(nums[0]);
        for (int i=1; i<n; i++) {
            prefix.push_back(prefix[i-1] + nums[i]);
        }

        vector<vector<int>> dp(n, vector<int>(k+1, INT_MAX));

        for (int i=n-1; i>=0; i--) {
            for (int j=1; j<=min(k, n-i); j++) {
                if (j==1) {
                    dp[i][j] = prefix[n-1] - prefix[i] + nums[i];
                    continue;
                }
                for (int l=i; l<n-1; l++) {
                    int first_part = prefix[l] - prefix[i] + nums[i];
                    int second_part = dp[l+1][j-1];
                    if (first_part > dp[i][j]) continue;
                    dp[i][j] = min(dp[i][j], max(first_part, second_part));
                }
            }
        }
        
        return dp[0][k];
    }
};
