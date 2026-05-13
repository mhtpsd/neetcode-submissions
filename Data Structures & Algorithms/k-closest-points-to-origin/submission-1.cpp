class Solution {
public:

    int mergeSort(vector<int>& nums, int left, int right) {

        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;

        int count = 0;

        count += mergeSort(nums, left, mid);
        count += mergeSort(nums, mid + 1, right);

        // Count reverse pairs
        int j = mid + 1;

        for (int i = left; i <= mid; i++) {

            while (j <= right &&
                   (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }

            count += (j - (mid + 1));
        }

        // Merge step
        vector<int> temp;

        int p1 = left;
        int p2 = mid + 1;

        while (p1 <= mid && p2 <= right) {

            if (nums[p1] <= nums[p2]) {
                temp.push_back(nums[p1++]);
            } else {
                temp.push_back(nums[p2++]);
            }
        }

        while (p1 <= mid)
            temp.push_back(nums[p1++]);

        while (p2 <= right)
            temp.push_back(nums[p2++]);

        for (int i = left; i <= right; i++) {
            nums[i] = temp[i - left];
        }

        return count;
    }

    int reversePairs(vector<int>& nums) {

        return mergeSort(nums, 0, nums.size() - 1);
    }
};