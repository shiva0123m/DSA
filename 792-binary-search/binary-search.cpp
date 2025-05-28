class Solution {
public:
    int Bsearch(int low,int high,int target,vector<int>& nums)
    {
        if(low>high)return -1;

        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (target > nums[mid])
        return Bsearch( mid + 1, high, target,nums);
        return Bsearch(low, mid - 1, target,nums);
    }
    int search(vector<int>& nums, int target) 
    {
        return Bsearch(0,nums.size()-1,target,nums);
    }
};