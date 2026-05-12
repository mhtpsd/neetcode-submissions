class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        // Empty tree
        if(root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int size = q.size();

            // Process one level
            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Last node of current level
                if(i == size - 1) {
                    ans.push_back(node->val);
                }

                if(node->left != nullptr) {
                    q.push(node->left);
                }

                if(node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }

        return ans;
    }
};