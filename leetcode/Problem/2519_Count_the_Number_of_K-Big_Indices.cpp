class Solution {
public:
    int kBigIndices(vector<int>& nums, int k) {
        priority_queue<int> left, right;
        int n = nums.size();

        for (int i=0; i<k; i++) {
            left.push(nums[i]);
            right.push(nums[n-1-i]);
        }

        int rst = 0;
        vector<int> left_true(n, 0);

        for (int i=k; i<n-k; i++) {
            if (nums[i] > left.top()) {
                left_true[i] = 1;
            }
            else {
                left.pop();
                left.push(nums[i]);
            }
        }
        for (int i=n-k-1; i>=k; i--) {
            if (nums[i] > right.top()) {
                rst += left_true[i];
            }
            else {
                right.pop();
                right.push(nums[i]);
            }
        }


        return rst;
    }
};
