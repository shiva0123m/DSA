class Solution 
{
    public boolean dfs(int i,int j,int wordIndex,String word,char[][]board)
    {
        if(wordIndex==word.length())
        {
            return true;
        }
        if(i<0 || i>=board.length || j<0 || j>=board[0].length)
        {
            return false;
        }
        if(board[i][j]!=word.charAt(wordIndex))
        {
            return false;
        }

        char temp=board[i][j];

        
        board[i][j]='#';
        boolean isFound=dfs(i-1,j,wordIndex+1,word,board) ||
        dfs(i,j-1,wordIndex+1,word,board)||
        dfs(i+1,j,wordIndex+1,word,board)||
        dfs(i,j+1,wordIndex+1,word,board);
        
        board[i][j]=temp;

        return isFound;
    }
    public boolean exist(char[][] board, String word) 
    {
        int len=word.length();

        for(int i=0;i<board.length;i++)
        {
            for(int j=0;j<board[0].length;j++)
            {
                if(dfs(i,j,0,word,board)==true)
                {
                    return true;
                }
            }
        }
        return false;
    }
}