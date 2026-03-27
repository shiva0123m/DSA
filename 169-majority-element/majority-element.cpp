class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int ans=nums[0];
        int count=0;
        for(int it : nums)
        {
            if(it==ans)
            {
                count++;
            }
            else if(count==0)
            {
                ans=it;
                count=1;
            }
            else
            {
                count--;
            }

        }    
        return ans;
    }
};