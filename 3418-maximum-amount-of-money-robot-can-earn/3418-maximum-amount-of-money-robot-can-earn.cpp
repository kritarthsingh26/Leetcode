class Solution {
public:
    int m, n;
    int t[501][501][3];

    int solve(vector<vector<int>>& coins, int i, int j, int neu) {
        // Base case: reached bottom-right
        if (i == m - 1 && j == n - 1) {
            if (coins[i][j] < 0 && neu > 0) {
                return 0; // neutralize robber
            }
            return coins[i][j];
        }

        // Out of bounds
        if (i >= m || j >= n) {
            return INT_MIN;
        }

        // Memoization
        if (t[i][j][neu] != INT_MIN) {
            return t[i][j][neu];
        }

        // Take current cell value
        int take = coins[i][j] + max(
            solve(coins, i + 1, j, neu),
            solve(coins, i, j + 1, neu)
        );

        // Skip (neutralize) if negative and we have power
        int skip = INT_MIN;
        if (coins[i][j] < 0 && neu > 0) {
            skip = max(
                solve(coins, i + 1, j, neu - 1),
                solve(coins, i, j + 1, neu - 1)
            );
        }

        return t[i][j][neu] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();

        // Initialize DP with INT_MIN
        for (int i = 0; i < 501; i++) {
            for (int j = 0; j < 501; j++) {
                for (int k = 0; k < 3; k++) {
                    t[i][j][k] = INT_MIN;
                }
            }
        }

        return solve(coins, 0, 0, 2);
    }
};