class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        // maximum possible number is 1+2+3+4+5+6+7+8+9=45
        if (n>45) return {};
        vector<vector<int>> ans;
        vector<int> tmp;

        dfs(0, n, k, tmp, ans);
        return ans;
    }

    void dfs(int cur, int target, int k, vector<int>& tmp, vector<vector<int>>& ans) {
        if (k == 0 && target == 0) {
            ans.push_back(tmp);
            return;
        }
        if (k==0) return;

        for (int i=cur+1; i<=9; i++) {
            tmp.push_back(i);
            dfs(i, target-i, k-1, tmp, ans);
            tmp.pop_back();
        }

        return;
    }
};
