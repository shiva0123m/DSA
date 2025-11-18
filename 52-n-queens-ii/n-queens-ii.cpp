class Solution {
public:
    int ans = 0;

    void solve(int col, vector<string>& board, int n,
               vector<int>& row, vector<int>& lowerDiagonal, vector<int>& upperDiagonal)
    {
        if (col == n) {
            ans++;
            return;
        }

        for (int r = 0; r < n; r++) {
            if (row[r] == 0 && 
                lowerDiagonal[r + col] == 0 && 
                upperDiagonal[n - 1 + col - r] == 0)
            {
                board[r][col] = 'Q';
                row[r] = 1;
                lowerDiagonal[r + col] = 1;
                upperDiagonal[n - 1 + col - r] = 1;

                solve(col + 1, board, n, row, lowerDiagonal, upperDiagonal);

                board[r][col] = '.';
                row[r] = 0;
                lowerDiagonal[r + col] = 0;
                upperDiagonal[n - 1 + col - r] = 0;
            }
        }
    }

    int totalNQueens(int n) {
        vector<int> row(n, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);

        vector<string> board(n, string(n, '.'));

        solve(0, board, n, row, lowerDiagonal, upperDiagonal);

        return ans;
    }
};
