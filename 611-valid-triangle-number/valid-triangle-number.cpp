class Solution {
public:
    int triangleNumber(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int hypoteneus=n-1;
        int adjacentSide1=0;
        int adjacentSide2=0;
        int totalCombinations=0;
        while(hypoteneus>=2)
        {
            adjacentSide1=0;
            adjacentSide2=hypoteneus-1;
            while(adjacentSide1<adjacentSide2)
            {
                if((nums[adjacentSide1]+nums[adjacentSide2])<=nums[hypoteneus])
                {
                    adjacentSide1++;
                }
                else
                {
                    totalCombinations+=adjacentSide2-adjacentSide1;
                    adjacentSide2--;
                }
            }
            hypoteneus--;
            
        }
        return totalCombinations;
    }
};