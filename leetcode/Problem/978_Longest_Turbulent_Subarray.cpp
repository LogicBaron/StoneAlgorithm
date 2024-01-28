class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();

        if (n==1) return 1;

        vector<int> dp(2, 1);

        if (arr[0] < arr[1]) {
            dp[0] = 2;
        }
        else if (arr[0] > arr[1]) {
            dp[1] = 2;
        }

        int rst = max(dp[0], dp[1]);

        for (int i=2; i<n; i++) {
            if (arr[i-1] < arr[i]) {
                dp[0] = dp[1]+1;
                dp[1] = 1;
            }
            else if (arr[i-1] > arr[i]) {
                dp[1] = dp[0]+1;
                dp[0] = 1;
            }
            else {
                dp[0] = 1;
                dp[1] = 1;
            }
            rst = max(rst, max(dp[0], dp[1]));
        }

        return rst;
    }
};
