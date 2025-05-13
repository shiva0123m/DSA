class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // First pass: mark rows and columns that should be zero
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Second pass: set marked rows to zero
        for(int i = 0; i < n; i++)
        {
            if(row[i] == 1)
            {
                for(int j = 0; j < m; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Third pass: set marked columns to zero
        for(int j = 0; j < m; j++)
        {
            if(col[j] == 1)
            {
                for(int i = 0; i < n; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
