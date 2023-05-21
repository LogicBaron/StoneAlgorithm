/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    
    bool dfs(TreeNode* cur, TreeNode* p, TreeNode* q) {
        if (cur==NULL) {
            return false;
        }
        
        bool left = dfs(cur->left, p, q);
        bool right = dfs(cur->right, p, q);
        
        bool mid = (cur==p or cur==q);
        
        if (mid+left+right >= 2) {
            ans = cur;
        }
        
        return mid or left or right;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};
