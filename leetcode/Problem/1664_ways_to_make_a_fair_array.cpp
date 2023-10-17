class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>(n, ""));

        for (int step=1; step<=n; step++) {
            for (int i=0; i<=n-step; i++) {
                int j = i + step - 1;

                for (int k=i-1; k<j; k++) {
                    string cur;
                    if (k<i) {
                        // initially, use raw substring of s.
                        cur = s.substr(i, step);
                        dp[i][j] = cur;
                    }
                    else {
                        // left encoded text + right encoded text.
                        string left = dp[i][k];
                        string right = dp[k+1][j];
                        cur = left + right;
                    }

                    // if text is encodable, encode it.
                    auto pos = (cur+cur).find(cur, 1);
                    if (pos < cur.size()) {
                        cur = to_string(cur.size()/pos) + "[" + cur.substr(0, pos) +  "]";
                    }

                    if (cur.size() < dp[i][j].size()) {
                        dp[i][j] = cur;
                    }
                }
            }

        }

        return dp[0][n-1];
    }
};
