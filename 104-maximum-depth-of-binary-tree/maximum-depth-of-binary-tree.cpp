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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        //if tree is empty ; basecase when traversal reaches last node of tree

        int leftDepth = maxDepth(root->left);//maxDepth(9)        maxDepth(15)       maxDepth(NULL)
        int rightDepth = maxDepth(root->right);//maxDepth(20)     maxDepth(7)        maxDepth(2)
        //for maxDepth(3) ie.value of root node ie. 3                                for maxDepth(1) ie.root=1
        //up next is when root=9 so since it has no child maxDepth(NULL)=0 hence not considered further; same for 15 and 7 
        //next up when root node is 20 ie.maxDepth(20)
        return 1 + max(leftDepth, rightDepth);//max(maxDepth(9), maxDepth(20)) ie. max(1,2)  1+2=3      
                                              //max(maxDepth(15), maxDepth(7)) ie. max(1,1)  1+1=2
                                              //since 3>2; 3 is considered as max
                                              ////max(maxDepth(NULL), maxDepth(2)) ie. max(0,1) 1+1=2
    }
};