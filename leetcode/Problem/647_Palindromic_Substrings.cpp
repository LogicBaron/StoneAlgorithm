class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;

        int n = s.size();

        vector<vector<int>> dp(n, vector<int> (n, 0));

        for (int step=0; step<n; step++) {
            for (int i=0; i<n-step; i++) {
                
                // if i == 0, all palindrome
                if (step == 0) dp[i][i+step] = 1;

                else if (step == 1) {
                    dp[i][i+step] = s[i]==s[i+step];
                }
                
                else {
                    if (dp[i+1][i+step-1] && s[i]==s[i+step]) {
                        dp[i][i+step] = 1;
                    }
                }
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                ans += dp[i][j];
            }
        } 


        return ans;
    }
};
