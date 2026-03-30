class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int maxi=nums[0];
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum=nums[i]+sum;
            maxi=max(maxi,sum);
            if(sum<0)
            {
                sum=0;
            }

        }
        return maxi;
    }
};