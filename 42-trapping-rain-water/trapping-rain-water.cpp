class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n=height.size();
         if (n == 0) return 0;
        vector<int>suffixGreaterBuilding(n);
        vector<int>prefixGreaterBuilding(n);
        suffixGreaterBuilding[n-1]=height[n-1];
        prefixGreaterBuilding[0]=height[0];
        int temp=suffixGreaterBuilding[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffixGreaterBuilding[i]=max(height[i],temp);
            temp=max(height[i],temp);
        }
        temp=prefixGreaterBuilding[0];
        for(int i=0;i<n;i++)
        {
            prefixGreaterBuilding[i]=max(height[i],temp);
            temp=max(height[i],temp);
        }
        int totalWater=0;
        for(int i=0;i<n;i++)
        {
            totalWater+=min(suffixGreaterBuilding[i],prefixGreaterBuilding[i])-height[i];
        }
        return totalWater;
    }
};