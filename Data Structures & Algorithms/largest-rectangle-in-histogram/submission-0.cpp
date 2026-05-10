class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {

            // virtual 0 height at end
            int currHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() &&
                   currHeight < heights[st.top()]) {

                int height = heights[st.top()];
                st.pop();

                int right = i;

                int left =
                    st.empty() ? -1 : st.top();

                int width = right - left - 1;

                maxArea =
                    max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};
