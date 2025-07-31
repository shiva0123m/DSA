class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    bool dfs(string src, string dst, unordered_set<string>& visited, double& result, double current) {
        if (visited.count(src)) return false;
        visited.insert(src);
        if (src == dst) {
            result = current;
            return true;
        }
        for (auto& [neighbor, weight] : graph[src]) {
            if (dfs(neighbor, dst, visited, result, current * weight)) {
                return true;
            }
        }
        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Build the graph
        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        // Answer the queries
        vector<double> results;
        for (auto& query : queries) {
            string src = query[0];
            string dst = query[1];
            if (!graph.count(src) || !graph.count(dst)) {
                results.push_back(-1.0);
            } else if (src == dst) {
                results.push_back(1.0);
            } else {
                unordered_set<string> visited;
                double result = -1.0;
                dfs(src, dst, visited, result, 1.0);
                results.push_back(result);
            }
        }

        return results;
    }
};
