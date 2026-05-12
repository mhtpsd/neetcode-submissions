class Solution {
public:

    int dfs(TreeNode* root, int maxValue) {

        if(root == nullptr) {
            return 0;
        }

        int count = 0;

        // Current node is good
        if(root->val >= maxValue) {
            count = 1;
        }

        // Update maximum value in path
        maxValue = max(maxValue, root->val);

        // Count good nodes in left and right subtree
        count += dfs(root->left, maxValue);
        count += dfs(root->right, maxValue);

        return count;
    }

    int goodNodes(TreeNode* root) {

        return dfs(root, root->val);
    }
};