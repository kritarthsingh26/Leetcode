class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) 
    {
        int m = cost.size();
        int n = cost[0].size();

       
        vector<int> minCost(n, INT_MAX);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                minCost[j] = min(minCost[j], cost[i][j]);
            }
        }

        int totalMask = (1 << n);

        vector<vector<int>> dp(m + 1, vector<int>(totalMask, INT_MAX));
        dp[0][0] = 0;

        for (int i = 0; i < m; i++) 
        {
            for (int mask = 0; mask < totalMask; mask++) 
            {
                if (dp[i][mask] == INT_MAX) continue;

                for (int j = 0; j < n; j++) 
                {
                    int newMask = mask | (1 << j);
                    dp[i + 1][newMask] = min(
                        dp[i + 1][newMask],
                        dp[i][mask] + cost[i][j]
                    );
                }
            }
        }

        int ans = INT_MAX;

        for (int mask = 0; mask < totalMask; mask++) 
        {
            if (dp[m][mask] == INT_MAX) continue;

            int extra = 0;

            for (int j = 0; j < n; j++) 
            {
                if (!(mask & (1 << j))) {
                    extra += minCost[j];
                }
            }

            ans = min(ans, dp[m][mask] + extra);
        }

        return ans;
    }
};