class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string src, string dest, unordered_set<string>& vis) {
        if (graph.find(src) == graph.end()) return -1.0;
        if (src == dest) return 1.0;

        vis.insert(src);

        for (auto &neigh : graph[src]) {
            string next = neigh.first;
            double weight = neigh.second;

            if (vis.count(next)) continue;

            double res = dfs(next, dest, vis);
            if (res != -1.0) {
                return res * weight;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, 
                                vector<vector<string>>& queries) 
    {
      
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        vector<double> ans;

        for (auto &q : queries) {
            string src = q[0];
            string dest = q[1];

            unordered_set<string> vis;
            double res = dfs(src, dest, vis);
            ans.push_back(res);
        }

        return ans;
    }
};