class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        maze[entrance[0]][entrance[1]] = '+';  // mark entrance as visited
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            ++steps;

            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front(); q.pop();
                
                for (auto& dir : directions) {
                    int nx = x + dir[0], ny = y + dir[1];
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && maze[nx][ny] == '.') {
                        if (nx == 0 || ny == 0 || nx == m - 1 || ny == n - 1)
                            return steps;  
                        maze[nx][ny] = '+';  
                        q.push({nx, ny});
                    }
                }
            }
        }

        return -1;  
    }
};
