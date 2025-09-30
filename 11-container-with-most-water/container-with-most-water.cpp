class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int n=height.size()-1;

        int left=0;
        int right=n;
        int maxArea=0;
        while(left<right)
        {
            int minheight=min(height[left],height[right]);
            int width=right-left;
            int area=minheight*width;
            maxArea=max(maxArea,area);
            if (height[left] < height[right])
                ++left;
            else
                --right;
        }
        return maxArea;
    }
};