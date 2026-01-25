class Solution {
public:
    int fibAns(int n,vector<int>&ans)
    {
        if(ans[n]!=-1)
            return ans[n];
        
        ans[n]=fibAns(n-1,ans)+fibAns(n-2,ans);        
        return ans[n];
    }
    int fib(int n) 
    {
        if(n<=1)
        {
            return n;
        }
        vector<int>ans(n+1,-1);
        ans[0]=0;
        ans[1]=1;

        return fibAns(n,ans);
    }
};

// using memoization 