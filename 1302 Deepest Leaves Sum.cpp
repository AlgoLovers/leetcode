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
    pair<int, int> ans{0, 0};
    void dfs(TreeNode* cur, int depth) {
        if(cur == NULL) {
            return;
        }
        if(ans.first < depth) {
            ans.second = cur->val;
            ans.first = depth;
        } else if(ans.first == depth) {
            ans.second += cur->val;
        }
        dfs(cur->left, depth + 1);
        dfs(cur->right, depth + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return ans.second;
    }
};