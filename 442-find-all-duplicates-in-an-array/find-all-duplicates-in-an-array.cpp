class Solution 
{
    public:
        vector<int> findDuplicates(vector<int>& nums) 
        {
            int n=nums.size();
            vector<int>ans;
            for(int i=0;i<n;i++)
            {
                int index=abs(nums[i]);

                if(nums[index-1]>0)
                {
                    nums[index-1]=-nums[index-1];
                }
                else
                {
                    ans.push_back(index);
                }
            }
            return ans;
        }
};