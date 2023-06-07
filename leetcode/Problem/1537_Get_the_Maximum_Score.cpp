class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), l = 0, r = 0;
        long long l_sum = 0, r_sum = 0, mod = 1e9+7;
        long long rst = 0;
        
        while (l<n1 && r<n2) {
            if (nums1[l] == nums2[r]) {
                rst += max(l_sum, r_sum) + nums1[l];
                rst %= mod;
                l++;
                r++;
                l_sum = 0;
                r_sum = 0;
            }
            else if (nums1[l] < nums2[r]) {
                l_sum += nums1[l];
                l++;
            }
            else {
                r_sum += nums2[r];
                r++;
            }
        }

        for (int i=l; i<n1; i++) {
            l_sum += nums1[i];
        }
        for (int i=r; i<n2; i++) {
            r_sum += nums2[i];
        }
        rst += max(l_sum, r_sum);
        rst %= mod;

        return rst;
    }
};
