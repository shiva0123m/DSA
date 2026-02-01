class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        int prev2=0;
        int prev1=0;
        int curr=0;

        for(int i=0;i<n;i++)
        {
            curr=max(prev1,nums[i]+prev2);
            prev2=prev1;
            prev1=curr;
        }

        return curr;  
    }
};