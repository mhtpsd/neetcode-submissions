class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long hours = 0;

        for (int pile : piles) {

            hours += (pile + k - 1) / k;
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles,
                       int h) {

        int left = 1;

        int right =
            *max_element(piles.begin(),
                         piles.end());

        int answer = right;

        while (left <= right) {

            int mid =
                left + (right - left) / 2;

            if (canEat(piles, h, mid)) {

                answer = mid;
                right = mid - 1;
            }

            else {
                left = mid + 1;
            }
        }

        return answer;
    }
};
