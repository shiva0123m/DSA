class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        int n = board.size();
        int m = board[0].size();

        // Vectors for checking all 8 directions
        vector<int> rowDir{-1, -1, 0, 1, 1, 1, 0, -1};
        vector<int> colDir{0, 1, 1, 1, 0, -1, -1, -1};

        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < m; col++)
            {
                int countNeighbourers = 0;

                for(int i = 0; i < 8; i++)
                {
                    int newRow = row + rowDir[i];
                    int newCol = col + colDir[i];

                    // Count neighbors that were originally alive (1 or -1)
                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                       (board[newRow][newCol] == 1 || board[newRow][newCol] == -1))
                    {
                        countNeighbourers++;
                    }
                }

                // Live cell with fewer than 2 or more than 3 neighbors dies
                if(board[row][col] == 1 && (countNeighbourers < 2 || countNeighbourers > 3))
                {
                    board[row][col] = -1; // Mark as will die
                }

                // Dead cell with exactly 3 live neighbors becomes alive
                if(board[row][col] == 0 && countNeighbourers == 3)
                {
                    board[row][col] = 3; // Mark as will become alive
                }
            }
        } 

        // Final pass to update the board
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] > 0)
                {
                    board[i][j] = 1; // Alive
                }
                else
                {
                    board[i][j] = 0; // Dead
                }
            }
        }   
    }
};
