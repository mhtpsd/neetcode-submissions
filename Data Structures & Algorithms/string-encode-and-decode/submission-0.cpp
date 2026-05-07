class Solution {
public:

    string encode(vector<string>& strs) {
        string result;

        for (string s : strs) {
            result += to_string(s.size()) + "#" + s;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;

        while (i < s.size()) {
            // find delimiter #
            int j = i;

            while (s[j] != '#') {
                j++;
            }

            // length of string
            int len = stoi(s.substr(i, j - i));

            // extract actual string
            string word = s.substr(j + 1, len);

            result.push_back(word);

            // move to next encoded part
            i = j + 1 + len;
        }

        return result;
    }
};
