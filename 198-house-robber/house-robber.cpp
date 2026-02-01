class Solution {
public:
    int robMax(int n,vector<int>&nums,vector<int>&dp)
    {
        if (n < 0) return 0;
        if(dp[n]!=-1)
        {
           return dp[n];
        }
        dp[n]=max(nums[n]+robMax(n-2,nums,dp),robMax(n-1,nums,dp));
        return dp[n];
    }
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        dp[0]=nums[0];
        if(n==1)
        {
            return nums[0];
        }
        dp[1]=max(nums[0],nums[1]);
        return robMax(n-1,nums,dp);   
    }
};