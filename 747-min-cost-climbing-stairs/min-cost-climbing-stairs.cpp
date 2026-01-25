class Solution {
public:
    int findCost(int i,vector<int>&cost,vector<int>&ans)
    {
        if (i == 0) return cost[0];
        if (i == 1) return cost[1];
        if(ans[i]!=-1)
        {
            return ans[i];
        }
        ans[i]= cost[i]+min(findCost(i-1,cost,ans),findCost(i-2,cost,ans));
        return ans[i];
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n=cost.size();
        vector<int>ans(n,-1);
        return min(findCost(n-1,cost,ans),findCost(n-2,cost,ans));    
    }
};