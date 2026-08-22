class Solution 
{
public:
    vector<vector<string>>ans;
public:
    void mark(int row,vector<int>&col,vector<string>&board,vector<int>&upperDiagonal,vector<int>&lowerDiagonal,int n)
    {
        if(row==n)
        {
            ans.push_back(board);
            return; 
        }

        for(int i=0;i<n;i++)
        {
            if(col[i] || upperDiagonal[row-i+n-1] || lowerDiagonal[row+i])
                continue;
            
            col[i]=1;
            upperDiagonal[row-i+n-1]=1;
            lowerDiagonal[row+i]=1;
            board[row][i]='Q';
            mark(row+1,col,board,upperDiagonal,lowerDiagonal,n);
            col[i]=0;
            upperDiagonal[row-i+n-1]=0;
            lowerDiagonal[row+i]=0;
            board[row][i]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string>board(n,string(n,'.'));

        vector<int>upperDiagonal(2*n-1,0);
        vector<int>lowerDiagonal(2*n-1,0);
        vector<int>col(n,0);

        mark(0,col,board,upperDiagonal,lowerDiagonal,n);
        return ans;
    }
};