class Solution {
public:
    int f(vector<vector<int>>& dp, vector<int>& cookies, int x, int k) {
        if (dp[x][k] != INT_MAX) return dp[x][k];
        
        for (int y=x; y>0; y=x&(y-1)) {
            dp[x][k] = min(dp[x][k], max(
                f(dp, cookies, x-y, k-1),
                f(dp, cookies, y, 1)
                )
            );
        }

        return dp[x][k];
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        int N = (1<<n) - 1;
        vector<vector<int>> dp(N+1, vector<int>(k+1, INT_MAX));

        for (int i=0; i<=N; i++) {
            int tmp = 0, j = i, index=0;
            while (j>0) {
                if (j&1) tmp+=cookies[index];
                j >>= 1;
                index++;
            }
            dp[i][1] = tmp;
        }

        return f(dp, cookies, N, k);
    }
};
