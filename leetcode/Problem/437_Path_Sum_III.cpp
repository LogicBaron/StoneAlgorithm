/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<long, int> mp;
    int count = 0;

    void countPathSum(TreeNode* cur, int target, long sum) {
        if (cur == nullptr) return;
        sum += cur->val;
        if (mp.find(sum - target) != mp.end()) {
            count += mp[sum - target];
        }
        mp[sum]++;
        countPathSum(cur->left, target, sum);
        countPathSum(cur->right, target, sum);
        mp[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        countPathSum(root, targetSum, 0);
        return count;
    }
};
