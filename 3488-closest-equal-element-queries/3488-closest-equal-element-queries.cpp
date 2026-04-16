class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> dist(n, INT_MAX);

        for (auto &it : mp) {
            auto &vec = it.second;
            int k = vec.size();

            if (k == 1) continue;

            vector<int> ext = vec;
            for (int x : vec) {
                ext.push_back(x + n);
            }

            for (int i = 0; i < ext.size() - 1; i++) {
                int d = ext[i + 1] - ext[i];

                int idx1 = ext[i] % n;
                int idx2 = ext[i + 1] % n;

                dist[idx1] = min(dist[idx1], d);
                dist[idx2] = min(dist[idx2], d);
            }
        }

        vector<int> ans;
        for (int q : queries) {
            if (dist[q] == INT_MAX) ans.push_back(-1);
            else ans.push_back(dist[q]);
        }

        return ans;
    }
};