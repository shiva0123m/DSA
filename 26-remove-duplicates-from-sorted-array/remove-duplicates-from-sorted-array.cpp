class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int i=0;
        int second=1;
        while(second<nums.size())
        {
            if(nums[i]!=nums[second])
            {
                nums[i+1]=nums[second];
                i++;
            }
            second++;
        } 
        return i+1;   
    }
};