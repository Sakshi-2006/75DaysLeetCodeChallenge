class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both null → same
        if (p == NULL && q == NULL) return true;

        // One null or values different → not same
        if (p == NULL || q == NULL || p->val != q->val) return false;

        // Check left and right
        return isSameTree(p->left, q->left) && 
               isSameTree(p->right, q->right);
    }
};