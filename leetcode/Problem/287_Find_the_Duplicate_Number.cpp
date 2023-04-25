class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            int key = abs(nums[i])-1;
            nums[key] *= -1;
            if (nums[key] > 0) return key+1;
        }
        return -1;
    }
};
