class Codec {
public:

    void dfsSerialize(TreeNode* root, string& s) {
        if (!root) {
            s += "N,";
            return;
        }

        s += to_string(root->val) + ",";

        dfsSerialize(root->left, s);
        dfsSerialize(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        dfsSerialize(root, s);
        return s;
    }

    TreeNode* dfsDeserialize(vector<string>& nodes, int& index) {
        if (nodes[index] == "N") {
            index++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[index]));
        index++;

        root->left = dfsDeserialize(nodes, index);
        root->right = dfsDeserialize(nodes, index);

        return root;
    }

    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp;

        for (char c : data) {
            if (c == ',') {
                nodes.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }

        int index = 0;

        return dfsDeserialize(nodes, index);
    }
};