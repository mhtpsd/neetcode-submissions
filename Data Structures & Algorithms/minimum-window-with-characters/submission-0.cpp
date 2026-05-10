class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        // frequency of t
        for (char c : t) {
            need[c]++;
        }

        int have = 0;
        int required = need.size();

        int left = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            char c = s[right];

            window[c]++;

            // character requirement satisfied
            if (need.count(c) &&
                window[c] == need[c]) {
                have++;
            }

            // shrink while valid
            while (have == required) {

                // update answer
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // remove left char
                char leftChar = s[left];

                window[leftChar]--;

                // no longer valid
                if (need.count(leftChar) &&
                    window[leftChar] < need[leftChar]) {
                    have--;
                }

                left++;
            }
        }

        return minLen == INT_MAX
               ? ""
               : s.substr(start, minLen);
    }
};
