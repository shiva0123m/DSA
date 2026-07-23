class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& grid)
    {


        int rowSize=grid.size();
        int colSize=grid[0].size();

        if (row < 0 || col < 0 || row >= rowSize || col >= colSize)
            return;

        if (grid[row][col] == '0')
            return;

        grid[row][col] = '0';

        dfs(row-1,col,grid);
        dfs(row+1,col,grid);
        dfs(row,col-1,grid);
        dfs(row,col+1,grid);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int rowSize=grid.size();
        int colSize=grid[0].size();
        int island=0;
        for(int i=0;i<rowSize;i++)
        {
            for(int j=0;j<colSize;j++)
            {
                if(grid[i][j]=='1')
                {
                    island++;
                    dfs(i,j,grid);
                }
            }
        }
        return island;
    }
};