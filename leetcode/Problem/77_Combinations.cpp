class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;

        backtrack(ans, cur, 0, n, k);

        return ans;
    }

    void backtrack(vector<vector<int>>& ans, vector<int>& cur, int index, int n, int k) {
        if (cur.size() == k) {
            ans.push_back(cur);
            return;
        }
        for (int i = index+1; i<=n; i++) {
            cur.push_back(i);
            backtrack(ans, cur, i, n, k);
            cur.pop_back();
        }
        return;
    }

};
