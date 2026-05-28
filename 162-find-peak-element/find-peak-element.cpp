class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int low=0;
        int high=nums.size()-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            bool isGreaterThanLeft=mid==0||nums[mid]>nums[mid-1]?true:false;
            bool isGreaterThanRight=mid==nums.size()-1||nums[mid]>nums[mid+1]?true:false;

            if(isGreaterThanLeft && isGreaterThanRight)
            {
                return mid;
            }
            else if(mid==0 || nums[mid]>nums[mid-1])
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return -1;
    }
};