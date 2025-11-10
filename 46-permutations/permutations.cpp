class Solution {
public:
    void FindPermutations(vector<int>&nums,vector<bool>&flag,int n,vector<vector<int>>&ans,vector<int>&ds)
    {
        if(ds.size()==n)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(!flag[i])
            {
                ds.push_back(nums[i]);
                flag[i]=1;
                FindPermutations(nums,flag,n,ans,ds);
                ds.pop_back();
                flag[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        
        vector<vector<int>>ans;
        vector<int>ds;
        int n=nums.size();
        vector<bool>flag(n,false);
        FindPermutations(nums,flag,n,ans,ds);
        return ans;
    }
};