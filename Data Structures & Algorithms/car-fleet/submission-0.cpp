class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, double>> cars;

        // {position, timeToTarget}
        for (int i = 0; i < n; i++) {

            double time =
                (double)(target - position[i]) / speed[i];

            cars.push_back({position[i], time});
        }

        // sort by position
        sort(cars.begin(), cars.end());

        int fleets = 0;
        double currentTime = 0;

        // process from closest to target
        for (int i = n - 1; i >= 0; i--) {

            double time = cars[i].second;

            // new fleet
            if (time > currentTime) {

                fleets++;
                currentTime = time;
            }
        }

        return fleets;
    }
};
