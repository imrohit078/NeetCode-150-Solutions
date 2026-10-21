class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n <= 1) return n;
        std::vector<std::pair<int, int>> cars(n);
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], speed[i]};
        }
        std::sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });
        int fleets = 0;
        double max_time = 0.0;
        for (int i = 0; i < n; ++i) {
            double time = static_cast<double>(target - cars[i].first) / cars[i].second;
            if (time > max_time) {
                fleets++;
                max_time = time;
            }
        }

        return fleets;
        
    }
};
