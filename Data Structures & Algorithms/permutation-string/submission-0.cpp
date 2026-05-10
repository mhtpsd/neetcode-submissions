class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> s1Count(26, 0);
        vector<int> windowCount(26, 0);

        // frequency of s1
        for (char c : s1) {
            s1Count[c - 'a']++;
        }

        int windowSize = s1.size();

        for (int i = 0; i < s2.size(); i++) {

            // add current character
            windowCount[s2[i] - 'a']++;

            // remove left character if window too big
            if (i >= windowSize) {
                windowCount[s2[i - windowSize] - 'a']--;
            }

            // compare frequencies
            if (windowCount == s1Count) {
                return true;
            }
        }

        return false;
    }
};
