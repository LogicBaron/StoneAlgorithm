class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> cur;
        f(nums, ans, cur, 0);
        return ans;
    }

    vector<vector<int>> f(vector<int>& nums, vector<vector<int>>& ans, vector<int>& cur, int index) {
        ans.push_back(cur);
        for (int i=index; i<nums.size(); i++) {
            if (i!=index && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            f(nums, ans, cur, i+1);
        }
        cur.pop_back();
        return ans;
    }
};
