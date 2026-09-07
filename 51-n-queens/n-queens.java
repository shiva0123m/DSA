class Solution {
    public void findTotalQueenPatterns(int row,int n,List<StringBuilder>board,int [] cols,int []upperDiagonal,int[] lowerDiagonal,List<List<String>> ans)
    {
        if(row==n)
        {
            List<String>validSolution= new ArrayList();
            //Converting string builder to normal array
            for(StringBuilder sb : board)
            {
                validSolution.add(sb.toString());
            }
            ans.add(validSolution);
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(cols[i]==1 || upperDiagonal[(n-1)+(row-i)]==1 || lowerDiagonal[(i+row)]==1)
                continue;

            board.get(row).setCharAt(i,'Q');
            cols[i]=1;
            upperDiagonal[(n-1)+(row-i)]=1;
            lowerDiagonal[(i+row)]=1;
            findTotalQueenPatterns(row+1,n,board,cols,upperDiagonal,lowerDiagonal,ans);
            board.get(row).setCharAt(i,'.');
            cols[i]=0;
            upperDiagonal[(n-1)+(row-i)]=0;
            lowerDiagonal[(i+row)]=0;

        }
    }
    public List<List<String>> solveNQueens(int n) 
    {
            List<StringBuilder> board = new ArrayList<>();

            for(int i=0;i<n;i++)
            {
                board.add(new StringBuilder(".".repeat(n)));
            }
            int[] cols=new int[n];
            int[] upperDiagonal=new int[2*n-1];
            int[] lowerDiagonal=new int[2*n-1];

            List<List<String>> ans=new ArrayList();
            findTotalQueenPatterns(0,n,board,cols,upperDiagonal,lowerDiagonal,ans);
            return ans;
    }
}