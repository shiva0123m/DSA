class Solution {
public:
    void generateSubsets(int index,vector<int>& nums,vector<int>&subsets,vector<vector<int>>&ans)
    {
        ans.push_back(subsets);
        for(int i=index;i<nums.size();i++)
        {
            if(i>index && nums[i]==nums[i-1])continue;
            subsets.push_back(nums[i]);
            generateSubsets(i+1,nums,subsets,ans);
            subsets.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<int>subsets;
        vector<vector<int>>ans;

        generateSubsets(0,nums,subsets,ans);
        return ans;
    }
};