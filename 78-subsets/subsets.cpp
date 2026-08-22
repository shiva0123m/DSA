class Solution {
public:
    void generateSubsets(int i,int n,vector<int>&subs,vector<int>&nums,vector<vector<int>>&ans)
    {
        if(i==n)
        {
            ans.push_back(subs);
            return;
        }

        subs.push_back(nums[i]);
        generateSubsets(i+1,n,subs,nums,ans);
        subs.pop_back();
        generateSubsets(i+1,n,subs,nums,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        vector<int>subs;

        generateSubsets(0,nums.size(),subs,nums,ans);
        return ans;
    }
};