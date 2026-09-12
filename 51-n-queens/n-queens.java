class Solution 
{
    public void findQueenPatterns(int row,char[][]  board,List<List<String>>ans,int[] dcol,int[] upperDiagonal,int[] lowerDiagonal,int n)
    {
        if(row==n)
        {
            List<String>currentBoard=new ArrayList<>();
            for (int i = 0; i < n; i++) 
            {
                String str=new String(board[i]);
                currentBoard.add(str);
            }
            ans.add(currentBoard);
            return ;
        }
        for(int col=0;col<n;col++)
        {
            if(dcol[col]==1 || upperDiagonal[(n-1)+(row-col)]==1 || lowerDiagonal[row+col]==1)
                continue;

            board[row][col]='Q';
            dcol[col]=1;
            upperDiagonal[(n-1)+(row-col)]=1;
            lowerDiagonal[row+col]=1;
            findQueenPatterns(row+1,board,ans,dcol,upperDiagonal,lowerDiagonal,n);
            board[row][col]='.';
            dcol[col]=0;
            upperDiagonal[(n-1)+(row-col)]=0;
            lowerDiagonal[row+col]=0;
        }
    }
    public List<List<String>> solveNQueens(int n) 
    {
        List<List<String>>ans=new ArrayList();
        char[][] board = new char[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(board[i], '.');
        }


        int[] dcol=new int[n];
        int[] upperDiagonal=new int[2*n-1];
        int[] lowerDiagonal= new int[2*n-1];

        findQueenPatterns(0,board,ans,dcol,upperDiagonal,lowerDiagonal,n);
        return ans;
    }
}