class Solution {
public:

    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(int index, int target, vector<int>& nums) {

        // Found valid combination
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        // Out of bounds or exceeded target
        if (index == nums.size() || target < 0) {
            return;
        }

        // Take current number
        curr.push_back(nums[index]);

        dfs(index, target - nums[index], nums);

        curr.pop_back();

        // Skip current number
        dfs(index + 1, target, nums);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        dfs(0, target, nums);

        return ans;
    }
};