class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(string& word, int idx, TrieNode* node) {

        if (idx == word.size()) {
            return node->isEnd;
        }

        char ch = word[idx];

        // wildcard case
        if (ch == '.') {

            for (int i = 0; i < 26; i++) {

                if (node->children[i] != nullptr) {

                    if (dfs(word, idx + 1, node->children[i])) {
                        return true;
                    }
                }
            }

            return false;
        }

        // normal character
        int pos = ch - 'a';

        if (node->children[pos] == nullptr) {
            return false;
        }

        return dfs(word, idx + 1, node->children[pos]);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {

        TrieNode* node = root;

        for (char ch : word) {

            int idx = ch - 'a';

            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};