class Solution {
public:

    vector<vector<string>> ans;

    vector<string> board;

    vector<int> col;
    vector<int> diag1;
    vector<int> diag2;

    void dfs(int row, int n) {

        // Valid board formed
        if (row == n) {

            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {

            int d1 = row - c + n - 1;
            int d2 = row + c;

            // Unsafe position
            if (col[c] ||
                diag1[d1] ||
                diag2[d2]) {

                continue;
            }

            // Place queen
            board[row][c] = 'Q';

            col[c] = 1;
            diag1[d1] = 1;
            diag2[d2] = 1;

            dfs(row + 1, n);

            // Backtrack
            board[row][c] = '.';

            col[c] = 0;
            diag1[d1] = 0;
            diag2[d2] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        board = vector<string>(n, string(n, '.'));

        col.resize(n, 0);

        diag1.resize(2 * n - 1, 0);
        diag2.resize(2 * n - 1, 0);

        dfs(0, n);

        return ans;
    }
};