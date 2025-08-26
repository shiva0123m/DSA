class Solution {
public:
    void fillQueen(int col,int n,vector<string>&board,vector<vector<string>>&ans,vector<int>&rows,vector<int>&upperDiagonal,vector<int>&lowerDiagonal)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(rows[row]==0 && upperDiagonal[n-1+col-row]==0 && lowerDiagonal[col+row]==0)
            {
                rows[row]=1;
                upperDiagonal[n-1+col-row]=1;
                lowerDiagonal[col+row]=1;
                board[row][col]='Q';
                fillQueen(col+1,n,board,ans,rows,upperDiagonal,lowerDiagonal);
                board[row][col]='.';
                rows[row]=0;
                upperDiagonal[n-1+col-row]=0;
                lowerDiagonal[col+row]=0;    
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) 
    {
      vector<vector<string>>ans;
      vector<string> board(n, string(n, '.'));
      vector<int>rows(n,0);
      vector<int>upperDiagonal(2*n-1,0);
      vector<int>lowerDiagonal(2*n-1,0); 
      fillQueen(0,n,board,ans,rows,upperDiagonal,lowerDiagonal);
      return ans;
    }
};