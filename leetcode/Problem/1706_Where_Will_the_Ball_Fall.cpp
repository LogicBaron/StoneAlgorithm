class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dp(n+1, vector<int>(m, -1));
        for (int i=0; i<m; i++) {
            dp[0][i] = i;
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]==1 && j+1<m && grid[i][j+1]==1) {
                    dp[i+1][j+1] = dp[i][j];
                }
                if (grid[i][j]==-1 && j-1>=0 && grid[i][j-1]==-1) {
                    dp[i+1][j-1] = dp[i][j];
                }
            }
        }

        vector<int> ans(m, -1);
        for (int i=0; i<m; i++) {
            if (dp[n][i] != -1) {
                ans[dp[n][i]] = i;
            }
        }

        return ans;
    }
};
