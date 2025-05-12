class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int maxn=0;
        int ctr=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {

                ctr++;
                maxn=max(ctr,maxn);
            }
            else
            {

                ctr=0;
            }
        
        }  
        return maxn;  
    }
};