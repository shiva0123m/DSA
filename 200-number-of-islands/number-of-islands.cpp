class Solution {
public:
    void BFS(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid, int n, int m) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nrow = r + drow[k];
                int ncol = c + dcol[k];

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                    grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    BFS(i, j, vis, grid, n, m);
                }
            }
        }
        return cnt;
    }
};
