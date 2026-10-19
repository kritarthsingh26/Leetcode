
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount,
                        vector<vector<int>>& queries) {

        int n = candiesCount.size();

        vector<bool> ans(queries.size());
        vector<long long> prefix(n);

        prefix[0] = candiesCount[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + candiesCount[i];
        }

        for (int i = 0; i < queries.size(); i++) {
            int type = queries[i][0];
            long long day = queries[i][1];
            long long cap = queries[i][2];

            long long first = (type == 0)
                              ? 1
                              : prefix[type - 1] + 1;

            long long last = prefix[type];

            long long mn = day + 1;
            long long mx = (day + 1) * cap;

            ans[i] = (mx >= first && mn <= last);
        }

        return ans;
    }
};
