class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int left=0;
        int sum=0;
        int n=nums.size();
        int minLen=INT_MAX;
        for(int right=0;right<n;right++)
        {
            sum+=nums[right];
            while (sum>=target)
            {
                minLen=min(minLen,right-left+1);
                sum-=nums[left];
                left++;
            }
        }    
        minLen=(minLen==INT_MAX)?0:minLen;

        return minLen;
    }
};