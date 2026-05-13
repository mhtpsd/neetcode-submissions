class Solution {
public:

    vector<vector<string>> ans;
    vector<string> curr;

    bool isPalindrome(string &s, int left, int right) {

        while (left < right) {

            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    void dfs(int index, string &s) {

        // Entire string partitioned
        if (index == s.size()) {

            ans.push_back(curr);
            return;
        }

        for (int end = index;
             end < s.size();
             end++) {

            if (isPalindrome(s, index, end)) {

                curr.push_back(
                    s.substr(index,
                             end - index + 1)
                );

                dfs(end + 1, s);

                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        dfs(0, s);

        return ans;
    }
};