class Solution {
private:
void findSubsets(vector<int>nums,int n,int i,vector<vector<int>> &ans,vector<int>&ds)
{
    if(i>=n)
    {
        ans.push_back(ds);
        return;
    }
    ds.push_back(nums[i]);
    findSubsets(nums,n,i+1,ans,ds);
    ds.pop_back();
    findSubsets(nums,n,i+1,ans,ds);
}
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int>ds;
        int n=nums.size();
        findSubsets(nums,n,0,ans,ds);
        return ans;
    }
};