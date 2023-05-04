class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero_p = 0, two_p = n;

        for (int i=0; i<n; i++) {
            if (nums[i] == 0) {
                nums[zero_p++] = 0; 
            }
            if (i < two_p) {
                if (nums[i] == 2) {
                    two_p--;
                }
            }
            else {
                if (nums[i] == 2) {
                    nums[--two_p] = 2;
                }
                nums[i] = 2;
            }
        }
        for (int i=zero_p; i<two_p; i++) {
            nums[i] = 1;
        }

        return;
    }
};
