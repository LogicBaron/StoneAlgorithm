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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        vector<int> cur;

        // cur.push_back(root->val);
        dfs(ans, cur, 0, root, targetSum);

        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& cur_path, int cur_sum, TreeNode* cur_node, int targetSum) {
        if (cur_node -> left == nullptr && cur_node -> right == nullptr) {
            if (cur_sum + cur_node->val == targetSum) {
                cur_path.push_back(cur_node->val);
                ans.push_back(cur_path);
                cur_path.pop_back();
            }
            return;
        }

        cur_path.push_back(cur_node->val);

        if (cur_node -> left != nullptr) {
            dfs(ans, cur_path, cur_sum + cur_node->val, cur_node->left, targetSum);
        }
        if (cur_node -> right != nullptr) {
            dfs(ans, cur_path, cur_sum + cur_node->val, cur_node->right, targetSum);
        }

        cur_path.pop_back();
        return;

    }
};
