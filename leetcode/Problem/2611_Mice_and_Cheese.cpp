class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<vector<int>> gap(n, vector<int>(2, 0));

        for (int i=0; i<n; i++) {
            gap[i] = {reward1[i]-reward2[i], reward1[i]};
        }

        sort(gap.begin(), gap.end(), [](vector<int>& a, vector<int>& b){return a[0]>b[0];});

        int ans = 0;
        for (int i=0; i<k; i++) {
            ans += gap[i][1];
        }
        for (int i=k; i<n; i++) {
            ans += gap[i][1] - gap[i][0];
        }

        return ans;

    }
};
