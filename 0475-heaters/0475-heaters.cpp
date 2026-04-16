class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        
        int ans = 0;

        for (int house : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), house);

            int dist1 = INT_MAX, dist2 = INT_MAX;

   
            if (it != heaters.end()) {
                dist1 = abs(*it - house);
            }

            if (it != heaters.begin()) {
                dist2 = abs(house - *(it - 1));
            }

            int closest = min(dist1, dist2);
            ans = max(ans, closest);
        }

        return ans;
    }
};