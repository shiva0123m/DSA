class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        queue<pair<int,int>>q;
        int row=grid.size();
        int col=grid[0].size();
        int fresh=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    fresh++;

                }
            }
        }

        if(fresh==0)return 0;
        int minutes=0;
        while(!q.empty())
        {
            int size=q.size();
            bool isRotten=false;
            while(size--)
            {
                auto node=q.front();
                q.pop();

                int row=node.first;
                int col=node.second;

                int di[]={1,-1,0,0};
                int dj[]={0,0,-1,1};

                for(int i=0;i<4;i++)
                {
                    int drow=row+di[i];
                    int dcol=col+dj[i];

                    if(drow>=0 && dcol>=0 && drow<grid.size() && dcol<grid[0].size() && grid[drow][dcol]==1)
                    {
                        q.push({drow,dcol});
                        grid[drow][dcol]=2;
                        fresh--;
                        isRotten=true;
                    }
                }
            }
            if(isRotten)minutes++;
        }
        return fresh>0?-1:minutes;
    }
};