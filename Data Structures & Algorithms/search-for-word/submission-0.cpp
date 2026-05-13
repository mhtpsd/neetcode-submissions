class Solution {
public:

    int rows, cols;

    bool dfs(vector<vector<char>>& board,
             string& word,
             int i,
             int j,
             int index) {

        // Entire word matched
        if (index == word.size()) {
            return true;
        }

        // Out of bounds or mismatch
        if (i < 0 || j < 0 ||
            i >= rows || j >= cols ||
            board[i][j] != word[index]) {

            return false;
        }

        char temp = board[i][j];

        // Mark visited
        board[i][j] = '#';

        bool found =
            dfs(board, word, i + 1, j, index + 1) ||
            dfs(board, word, i - 1, j, index + 1) ||
            dfs(board, word, i, j + 1, index + 1) ||
            dfs(board, word, i, j - 1, index + 1);

        // Backtrack
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};