class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // Check leaf node
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }

        // Recurse left & right
        int remaining = targetSum - root->val;

        return hasPathSum(root->left, remaining) ||
               hasPathSum(root->right, remaining);
    }
};