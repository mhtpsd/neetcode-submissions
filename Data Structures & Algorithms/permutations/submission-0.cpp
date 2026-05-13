class Solution {
public:

    vector<vector<int>> ans;
    vector<int> curr;
    vector<bool> used;

    void dfs(vector<int>& nums) {

        // One permutation formed
        if (curr.size() == nums.size()) {

            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i])
                continue;

            used[i] = true;

            curr.push_back(nums[i]);

            dfs(nums);

            curr.pop_back();

            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        used.resize(nums.size(), false);

        dfs(nums);

        return ans;
    }
};