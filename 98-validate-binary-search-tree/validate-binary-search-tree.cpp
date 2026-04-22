class Solution {
public:
    bool isValidBST(TreeNode* root, long long low, long long high) {
        if (!root) return true;

        if (root->val <= low || root->val >= high) return false;

        return isValidBST(root->left, low, root->val) &&
               isValidBST(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};