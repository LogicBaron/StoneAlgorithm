class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& costs) {
        stack<long long> stk;
        int n = nums.size();
        if (n==1) return 0;
        vector<long long> dp(n, 0);
        bool flag = nums[1]>=nums[0]; //if true, greater if false, smallerorequal
        stk.push(dp[0]);

        for (int i=1; i<n; i++) {
            dp[i] = dp[i-1];
            if ((flag && nums[i]<nums[i-1]) || (!flag && nums[i]>=nums[i-1])) {
                while (!stk.empty()) {
                    long long cur = stk.top();
                    stk.pop();
                    dp[i] = min(dp[i], cur);
                }
                flag = !flag;
            }
            dp[i] += costs[i];
            stk.push(dp[i]);
        }

        return dp[n-1];
    }
};
