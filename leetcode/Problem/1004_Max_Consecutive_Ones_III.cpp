class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0, left_k = k;
        int n = nums.size();
        int rst = 0;

        while (r<n) {
            if (nums[r] == 1) {
                rst = max(rst, r-l+1);
            }
            if (nums[r] == 0) {
                if (left_k == 0) {
                    while (nums[l]!=0) {
                        l++;
                    }
                    l++;
                }
                else {
                    left_k--;
                }
                rst = max(rst, r-l+1);
            }
            r++;
        }

        return rst;
    }
};
