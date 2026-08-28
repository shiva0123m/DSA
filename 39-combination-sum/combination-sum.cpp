class Solution {
public:
    void generateCombinations(int index,vector<int>& candidates,int target,vector<int>&subsets,vector<vector<int>>&ans)
    {

        if(target==0)
        {
            ans.push_back(subsets);
            return;
        }
        if(index==candidates.size() || target<0)
        {
            return;
        }
        if(target-candidates[index]>=0)
        {
            subsets.push_back(candidates[index]);
            generateCombinations(index,candidates,target-candidates[index],subsets,ans);
            subsets.pop_back();
        }
        generateCombinations(index+1,candidates,target,subsets,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int>subsets;
        vector<vector<int>>ans;

        generateCombinations(0,candidates,target,subsets,ans);
        return ans;
    }
};