class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int ans = -1;

        vector<int> pos(n, 0);

        while (k) {
            int cur = INT_MAX;
            int min_idx = n;
            for (int i=0; i<n; i++) {
                if (pos[i] < n && cur > matrix[i][pos[i]]) {
                    cur = matrix[i][pos[i]];
                    min_idx = i;
                }
            }
            pos[min_idx]++;
            k--;
            ans = cur;
        }


        return ans;
    }
};
