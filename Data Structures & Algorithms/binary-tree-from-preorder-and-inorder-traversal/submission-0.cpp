class Solution {
public:

    int preIndex = 0;

    TreeNode* build(vector<int>& preorder,
                    vector<int>& inorder,
                    int left,
                    int right,
                    unordered_map<int, int>& mp) {

        // No nodes in this range
        if(left > right) {
            return nullptr;
        }

        // Current root from preorder
        int rootValue = preorder[preIndex++];

        TreeNode* root = new TreeNode(rootValue);

        // Find root position in inorder
        int inorderIndex = mp[rootValue];

        // Build left subtree
        root->left = build(preorder, inorder,
                           left,
                           inorderIndex - 1,
                           mp);

        // Build right subtree
        root->right = build(preorder, inorder,
                            inorderIndex + 1,
                            right,
                            mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int, int> mp;

        // Store inorder indices
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(preorder,
                     inorder,
                     0,
                     inorder.size() - 1,
                     mp);
    }
};