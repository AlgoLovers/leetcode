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
    int getDepth(TreeNode* node) {
        if(node == NULL) {
            return 0;
        }
        int left = getDepth(node->left);
        if(left == -1) {
            return -1;
        }
        int right = getDepth(node->right);
        if(right == -1) {
            return -1;
        }
        int diff = abs(left - right);
        if(diff > 1) {
            return -1;
        }
        return 1 + max(getDepth(node->left), getDepth(node->right));
    }
    bool isBalanced(TreeNode* root) {
        if(getDepth(root) == -1) {
            return false;
        }
        return true;
    }
};