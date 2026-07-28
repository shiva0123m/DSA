class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int rowSize=mat.size();
        int colSize=mat[0].size();
        vector<vector<int>>distance(rowSize,vector<int>(colSize,-1));
        queue<pair<int,int>>q;

        for(int i=0;i<rowSize;i++)
        {
            for(int j=0;j<colSize;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    distance[i][j]=0;
                }
            }
        }
        int di[]={-1,1,0,0};
        int dj[]={0,0,-1,1};
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            int row=node.first;
            int col=node.second;

            for(int i=0;i<4;i++)
            {
                int drow=row+di[i];
                int dcol=col+dj[i];

                if(drow>=0 && dcol>=0 && drow<mat.size() && dcol<mat[0].size() && distance[drow][dcol]==-1)
                {
                    distance[drow][dcol]=distance[row][col]+1;
                    q.push({drow,dcol});
                }
            }
        }
        return distance;
    }
};