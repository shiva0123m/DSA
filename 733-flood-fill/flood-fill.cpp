class Solution {
public:
    void Fill(vector<vector<int>>& image, int sr, int sc, int color,int srcColor)
    {
        
        int row=image.size();
        int col=image[0].size();
        if(sr < 0 || sr >= row || sc < 0 || sc >= col)
            return;
        
        if(image[sr][sc]!=srcColor)return;

        image[sr][sc]=color;

        Fill(image,sr-1,sc,color,srcColor);
        Fill(image,sr,sc+1,color,srcColor);
        Fill(image,sr+1,sc,color,srcColor);
        Fill(image,sr,sc-1,color,srcColor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int srcColor=image[sr][sc];
        if (srcColor == color)
            return image;

        Fill(image,sr,sc,color,srcColor);

        return image;
    }
};