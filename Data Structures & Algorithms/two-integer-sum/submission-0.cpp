#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // check if complement already seen
            if (mp.count(complement)) {
                return {mp[complement], i};
            }

            // store current number
            mp[nums[i]] = i;
        }

        return {}; // not needed (guaranteed answer)
    }
};