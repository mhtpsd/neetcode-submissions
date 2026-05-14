class TrieNode {
public:
    TrieNode* children[26];
    string word;

    TrieNode() {
        word = "";

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Solution {
public:

    vector<string> ans;
    int rows, cols;

    void insert(TrieNode* root, string& word) {

        TrieNode* node = root;

        for (char ch : word) {

            int idx = ch - 'a';

            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {

        char ch = board[r][c];

        if (ch == '#' || node->children[ch - 'a'] == nullptr) {
            return;
        }

        node = node->children[ch - 'a'];

        // found word
        if (node->word != "") {
            ans.push_back(node->word);

            // avoid duplicates
            node->word = "";
        }

        // mark visited
        board[r][c] = '#';

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                dfs(board, nr, nc, node);
            }
        }

        // restore
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        TrieNode* root = new TrieNode();

        // build trie
        for (string& word : words) {
            insert(root, word);
        }

        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};