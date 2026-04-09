class NumArray {
    vector<int> ans;
public:
    NumArray(vector<int>& nums) 
    {
        int prefixSum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            ans.push_back(prefixSum);
        }
    }
    
    int sumRange(int left, int right) 
    {
        if(left == 0)
            return ans[right];
        return ans[right] - ans[left - 1];
    }
};