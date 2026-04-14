class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        
        const int INF = 1e9;

        vector<int> best(21, INF);

        for (auto &t : tires) {
            long long f = t[0], r = t[1];
            long long time = f;
            long long total = 0;

            for (int k = 1; k <= 20; k++) {
                total += time;
                if (total > INF) break;

                best[k] = min(best[k], (int)total);

                time *= r;
                if (time > INF) break;
            }
        }

        vector<int> dp(numLaps + 1, INF);
        dp[0] = 0;

        for (int i = 1; i <= numLaps; i++) {
            for (int k = 1; k <= 20 && k <= i; k++) {
                if (i == k) {
                    dp[i] = min(dp[i], best[k]);
                } else {
                    dp[i] = min(dp[i], dp[i - k] + best[k] + changeTime);
                }
            }
        }

        return dp[numLaps];
    }
};