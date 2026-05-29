class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int rowSize=matrix.size();
        int colSize=matrix[0].size();

        int row=0;
        int col=colSize-1;

        while(row<rowSize && col>=0)
        {
            int curr=matrix[row][col];

            if(curr==target)
            {
                return true;
            }
            else if(matrix[row][col]<target)
            {
                row++;
            }
            else
            {
                col--;
            }
        }    
        return false;
    }
};