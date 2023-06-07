class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        long long mod = 1e9+7;
        int n = binary.size();
        vector<vector<long long>> dp(n, vector<long long>(2, 0));

        int start = 0;
        while (binary[start] == '0') {
            start++;
        }
        if (start>=n) return 1;

        dp[start][1] = 1;
        for (int i=start+1; i<n; i++) {
            if (binary[i] == '0') {
                dp[i][0] = dp[i-1][0] + dp[i-1][1];
                dp[i][0] %= mod;
                dp[i][1] = dp[i-1][1];
            }
            else {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1]+1 + dp[i-1][0];
                dp[i][1] %= mod;
            }
        }
        
        int flag = (dp[n-1][0] > 0)||(binary[0]=='0');
        return (dp[n-1][0] + dp[n-1][1] + flag)%mod;
    }
};
