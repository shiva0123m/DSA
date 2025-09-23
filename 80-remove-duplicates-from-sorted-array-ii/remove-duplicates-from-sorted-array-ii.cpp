class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
    int ptr1=1;
    int ptr2=0;
    int count=1;
    if(nums.size()==0)
    {
        return 0;
    }
    for(ptr2=1;ptr2<nums.size();++ptr2)
    {
        if(nums[ptr2]==nums[ptr2-1])
        {
            count++;
        }
        else
        {
            count=1;
        }

        if(count<=2)
        {
            nums[ptr1]=nums[ptr2];
            ptr1++;
        }
        
    }
        return ptr1;
    }
};