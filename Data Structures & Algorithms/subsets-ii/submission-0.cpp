class Solution {
public:

    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(int index, vector<int>& nums) {

        ans.push_back(curr);

        for (int i = index; i < nums.size(); i++) {

            // Skip duplicates
            if (i > index &&
                nums[i] == nums[i - 1]) {
                continue;
            }

            curr.push_back(nums[i]);

            dfs(i + 1, nums);

            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        dfs(0, nums);

        return ans;
    }
};