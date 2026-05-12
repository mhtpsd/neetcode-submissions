class Solution {
public:
    
    int height(TreeNode* root) {

        // Base case
        if(root == nullptr) {
            return 0;
        }

        int leftHeight = height(root->left);

        // If left subtree already unbalanced
        if(leftHeight == -1) {
            return -1;
        }

        int rightHeight = height(root->right);

        // If right subtree already unbalanced
        if(rightHeight == -1) {
            return -1;
        }

        // Check balance condition
        if(abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // Return height
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};