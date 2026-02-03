class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (row < 0 || col < 0) return INT_MAX; // out of bounds
        if (row == 0 && col == 0) return grid[0][0];

        if (dp[row][col] != -1) return dp[row][col];

        return dp[row][col] =
            grid[row][col] + min(
                dfs(row - 1, col, grid, dp),
                dfs(row, col - 1, grid, dp)
            );
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return dfs(n - 1, m - 1, grid, dp);
    }
};
