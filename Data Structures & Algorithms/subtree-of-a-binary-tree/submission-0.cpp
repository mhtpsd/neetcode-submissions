class Solution {
public:

    bool isSame(TreeNode* p, TreeNode* q) {

        // Both are null
        if(p == nullptr && q == nullptr) {
            return true;
        }

        // One is null
        if(p == nullptr || q == nullptr) {
            return false;
        }

        // Values differ
        if(p->val != q->val) {
            return false;
        }

        // Check left and right subtrees
        return isSame(p->left, q->left) &&
               isSame(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // Empty tree check
        if(root == nullptr) {
            return false;
        }

        // If trees are same at current node
        if(isSame(root, subRoot)) {
            return true;
        }

        // Check left or right subtree
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};