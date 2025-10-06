class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;

        // First pass: mark the rows and columns
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) col0 = 0; // mark if first column needs to be zero
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // mark the row
                    matrix[0][j] = 0; // mark the column
                }
            }
        }

        // Second pass: set elements to 0 based on markers (excluding first row and col)
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Third pass: handle first row
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Fourth pass: handle first column
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
