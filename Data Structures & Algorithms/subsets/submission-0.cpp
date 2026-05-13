class Solution {
public:

    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(int index, vector<int>& nums) {

        // One subset formed
        if (index == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // Include nums[index]
        curr.push_back(nums[index]);
        dfs(index + 1, nums);

        // Backtrack
        curr.pop_back();

        // Exclude nums[index]
        dfs(index + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        dfs(0, nums);

        return ans;
    }
};