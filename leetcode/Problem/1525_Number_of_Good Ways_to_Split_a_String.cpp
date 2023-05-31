class Solution {
public:
    int numSplits(string s) {
        int l = s.size();
        int k = 'z'-'a'+1;
        vector<vector<int>> dp(l+1, vector<int>(k, 0));

        for (int i=1; i<=l; i++) {
            for (int j=0; j<k; j++) {
                dp[i][j] = dp[i-1][j];
            }
            dp[i][s[i-1]-'a']++;
        }

        int rst = 0;
        for (int i=1; i<l; i++) {
            int left = 0, right = 0;
            for (int j=0; j<k; j++) {
                if (dp[i][j] > 0) left++;
                if (dp[l][j] - dp[i][j] > 0) right++;
            }
            if (left==right) rst++;
        }

        return rst;
    }
};
