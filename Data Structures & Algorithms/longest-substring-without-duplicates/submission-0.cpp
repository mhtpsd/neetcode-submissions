class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {

            // remove duplicates
            while (window.count(s[right])) {
                window.erase(s[left]);
                left++;
            }

            // add current character
            window.insert(s[right]);

            // update answer
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
