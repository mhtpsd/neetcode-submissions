class Solution {
public:

    vector<string> ans;

    void dfs(string curr, int open, int close, int n) {

        // Valid parentheses formed
        if (curr.size() == 2 * n) {

            ans.push_back(curr);
            return;
        }

        // Add '('
        if (open < n) {
            dfs(curr + '(', open + 1, close, n);
        }

        // Add ')'
        if (close < open) {
            dfs(curr + ')', open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {

        dfs("", 0, 0, n);

        return ans;
    }
};