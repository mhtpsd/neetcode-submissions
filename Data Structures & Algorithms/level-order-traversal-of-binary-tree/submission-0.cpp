class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        // Empty tree
        if(root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int size = q.size();

            vector<int> level;

            // Process one level
            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                // Push left child
                if(node->left != nullptr) {
                    q.push(node->left);
                }

                // Push right child
                if(node->right != nullptr) {
                    q.push(node->right);
                }
            }

            ans.push_back(level);
        }

        return ans;
    }
};