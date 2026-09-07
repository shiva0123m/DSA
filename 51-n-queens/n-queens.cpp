class Solution {
public:
    void findTotalQueens(int row,vector<vector<string>>&ans,vector<int>&markCol,vector<int>&upperDiagonal,
    vector<int>&lowerDiagonal,int n,vector<string>&board)
    {
        if(row==n)
        {
            ans.push_back(board);
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(markCol[i]==1 || upperDiagonal[i+row] || lowerDiagonal[(n-1)+(row-i)] || board[row][i]=='Q')
            {
                continue;
            }

            board[row][i]='Q';
            markCol[i]=1;
            upperDiagonal[i+row]=1;
            lowerDiagonal[(n-1)+(row-i)]=1;
            findTotalQueens(row+1,ans,markCol,upperDiagonal,lowerDiagonal,n,board);
            board[row][i]='.';
            markCol[i]=0;
            upperDiagonal[i+row]=0;
            lowerDiagonal[(n-1)+(row-i)]=0;
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string>board(n,string(n,'.'));

        vector<int>markCol(n,0);
        vector<int>upperDiagonal(2*n-1,0);
        vector<int>lowerDiagonal(2*n-1,0);

        vector<vector<string>>ans;

        findTotalQueens(0,ans,markCol,upperDiagonal,lowerDiagonal,n,board);
        return ans;
    }
};