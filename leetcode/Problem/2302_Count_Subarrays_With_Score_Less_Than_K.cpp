class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int l=0, r=0;
        int n = nums.size();
        
        long long rst = 0;
        long long tmp_sum = 0;
        long long tmp_cnt = 1;

        while (r<n) {
            tmp_sum += nums[r];
            if (tmp_sum * (r-l+1) < k) {
                rst += (r-l+1);
            }
            else {
                tmp_sum -= nums[l++];
                while (tmp_sum * (r-l+1) >= k) {
                    tmp_sum -= nums[l++];
                }
                rst += (r-l+1);
            }
            r++;
        }

        return rst;
    }
};
