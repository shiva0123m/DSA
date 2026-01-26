class Solution {
public:
    int minimumCost(int n,vector<int>&cost,vector<int>&dp)
    {
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        dp[n]= cost[n]+min(minimumCost(n-1,cost,dp),minimumCost(n-2,cost,dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n=cost.size();
        vector<int>dp(n,-1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        return min(minimumCost(n-1,cost,dp),minimumCost(n-2,cost,dp));    
    }
};