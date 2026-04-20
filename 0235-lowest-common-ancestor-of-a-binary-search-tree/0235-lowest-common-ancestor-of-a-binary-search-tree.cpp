class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        while (root != NULL) {
            
            // both nodes are in left subtree
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            // both nodes are in right subtree
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            // split point (this is LCA)
            else {
                return root;
            }
        }
        return NULL;
    }
};