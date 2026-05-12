class Solution {
public:

    void inorder(TreeNode* root, vector<int>& nums) {

        if(root == nullptr) {
            return;
        }

        // Left
        inorder(root->left, nums);

        // Root
        nums.push_back(root->val);

        // Right
        inorder(root->right, nums);
    }

    int kthSmallest(TreeNode* root, int k) {

        vector<int> nums;

        inorder(root, nums);

        return nums[k - 1];
    }
};