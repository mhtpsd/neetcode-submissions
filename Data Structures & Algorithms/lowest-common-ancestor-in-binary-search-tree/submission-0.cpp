class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // If both nodes are smaller, move left
        if(p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // If both nodes are greater, move right
        if(p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // Otherwise current node is the LCA
        return root;
    }
};