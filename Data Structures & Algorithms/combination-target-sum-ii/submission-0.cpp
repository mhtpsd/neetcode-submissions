class Solution {
public:

    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(int index, int target, vector<int>& candidates) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > index &&
                candidates[i] == candidates[i - 1]) {
                continue;
            }

            // No need to continue
            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            // i + 1 because each element used once
            dfs(i + 1, target - candidates[i], candidates);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {

        sort(candidates.begin(), candidates.end());

        dfs(0, target, candidates);

        return ans;
    }
};