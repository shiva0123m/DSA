class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int front=0;
        int last=nums.size()-1;
        int valCounter=0;
        while(front<=last)
        {
            if(nums[front]==val)
            {
                nums[front]=nums[last];
                last--;
            }
            else
            {
                front++;
            }
        }
        return last+1;
    }
};