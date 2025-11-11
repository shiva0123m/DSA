#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<string>& board, vector<vector<string>>& ans, int col, int n,
               vector<int>& rows, vector<int>& upperDiagonal, vector<int>& lowerDiagonal) 
    {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (rows[i] == 0 && lowerDiagonal[i + col] == 0 && upperDiagonal[n - 1 + col - i] == 0) {
                board[i][col] = 'Q';
                rows[i] = 1;
                lowerDiagonal[i + col] = 1;
                upperDiagonal[n - 1 + col - i] = 1;

                solve(board, ans, col + 1, n, rows, upperDiagonal, lowerDiagonal);

                board[i][col] = '.';
                rows[i] = 0;
                lowerDiagonal[i + col] = 0;
                upperDiagonal[n - 1 + col - i] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board.push_back(s);
        }

        vector<vector<string>> ans;
        vector<int> rows(n, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);

        solve(board, ans, 0, n, rows, upperDiagonal, lowerDiagonal);
        return ans;
    }
};
