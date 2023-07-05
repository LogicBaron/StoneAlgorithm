class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, tmp = 0, last_zero = -1;

        for (int i=0; i<n; i++) {
            if (nums[i]==0) {
                tmp = (i-last_zero-1);
                last_zero = i;
            }
            else {
                tmp++;
                ans = max(ans, tmp);
            }
        }

        return ans==n?ans-1:ans;
    }
};
