class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vector<vector<pair<int, int>>> graph(n); 

        for (auto& edge : connections) {
            int u = edge[0], v = edge[1];
            graph[u].push_back({v, 1});  
            graph[v].push_back({u, 0});  
        }

        vector<bool> visited(n, false);
        return dfs(0, graph, visited);
    }

    int dfs(int node, vector<vector<pair<int, int>>>& graph, vector<bool>& visited) {
        visited[node] = true;
        int count = 0;

        for (auto& [neighbor, needsReversal] : graph[node]) {
            if (!visited[neighbor]) {
                count += needsReversal; // if original edge goes out, we need to reverse it
                count += dfs(neighbor, graph, visited);
            }
        }

        return count;
    }
};
