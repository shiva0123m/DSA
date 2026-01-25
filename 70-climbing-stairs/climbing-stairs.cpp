class Solution {
public:
    int findWays(int n,vector<int>&ans)
    {
        if(ans[n]!=-1)
        {
            return ans[n];
        }
        ans[n]= findWays(n-1,ans)+findWays(n-2,ans);
        return ans[n];
    }
    int climbStairs(int n) 
    {
        if(n<=1)
        {
            return n;
        }
        vector<int>ans(n+1,-1);
        ans[0]=1;
        ans[1]=1;
        return findWays(n,ans);   
    }
};