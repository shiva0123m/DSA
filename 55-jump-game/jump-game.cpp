class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n=nums.size();
        int maxReach=nums[0];
        for(int i=1;i<n;i++)
        {
            if(i>maxReach)
            {
                return false;
            }
            maxReach=max(maxReach,nums[i]+i);
        } 
        return true;   
    }
};