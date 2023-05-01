class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 10000));
        dp[n][m-1] = 1;
        dp[n-1][m] = 1;

        int x = n-1, y = m-1;
        
        while (x >=0 && y >= 0) {
            dp[x][y] = min(dp[x][y+1], dp[x+1][y]);
            dp[x][y] = max(1, dp[x][y] - dungeon[x][y]);
            if (x == 0 || y==m-1) {
                int tmp = x+y-1;
                x = min(n-1, tmp);
                y = tmp-x;
            }
            else {
                x--;
                y++;
            }
        } 

        return dp[0][0];
    }
};
