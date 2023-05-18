class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        long long l = 1, r = 1e9, mid, count, n = nums.size();

        while (l<r) {
            mid = (l+r)>>1;
            count = 0;
            for (int i=0; i<n; i++) {
                if (mid>=nums[i]) {
                    count ++;
                    i++;
                }
            }

            if (count<k) {
                l = mid+1;
            }
            else {
                r = mid;
            }
        }

        return l;

    }
};
