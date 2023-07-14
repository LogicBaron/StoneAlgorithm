class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, pair<int,int>> v;

        int max_num = -1;
        int ans = -1;
        for (int i=0; i<nums.size(); i++) {
            int k = nums[i]%space;
            v[k].first++;
            if (v[k].first==1) v[k].second = nums[i];
            v[k].second = min(v[k].second, nums[i]);
            if (v[k].first > max_num) {
                max_num = v[k].first;
                ans = v[k].second;
            }
            else if (v[k].first==max_num) ans = min(ans, v[k].second);
        }

        return ans;
    }
};
