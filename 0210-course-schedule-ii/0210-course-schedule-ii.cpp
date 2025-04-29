class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& order) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (int neighbor : graph[node]) {
            if (!vis[neighbor]) {
                if (dfs(neighbor, graph, vis, pathVis, order)) return true;
            } else if (pathVis[neighbor]) {
                return true; 
            }
        }

        pathVis[node] = 0;
        order.push_back(node); 
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<int> order;

        for (int i = 0; i < numCourses; ++i) {
            if (!vis[i]) {
                if (dfs(i, graph, vis, pathVis, order)) {
                    return {}; 
                }
            }
        }

        reverse(order.begin(), order.end()); 
        return order;
    }
};
