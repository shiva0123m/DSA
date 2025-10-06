class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        int col0=1;
        // Here I checked all the cells where the values are zero
         for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) col0 = 0; // this is explicit addition as j!=0 if else case was not working as expected
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // mark the row
                    matrix[0][j] = 0; // mark the column
                }
            }
        }
        // marking all the cells except 1st row and the 1st column
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }

        // marking 1 st row
        if(matrix[0][0]==0)
        {
            for(int i=0;i<m;i++)
                matrix[0][i]=0;
        }  
        // marking 1 st column
        if(col0==0)
        {
            for(int i=0;i<n;i++)
                matrix[i][0]=0;
        }
  
    }
};