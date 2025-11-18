class Solution {
public:
    void findCombinations(int i,vector<vector<int>>&ans,vector<int>&temp,int target,vector<int>&candidates)
    {
        if(i>=candidates.size())
        {
            if(target==0)
            {
                ans.push_back(temp);
                return;
            }
            return;
        }
        if(candidates[i]<=target)
        {
            temp.push_back(candidates[i]);
            findCombinations(i,ans,temp,target-candidates[i],candidates);
            temp.pop_back();
        }
        findCombinations(i+1,ans,temp,target,candidates);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int>temp;

        findCombinations(0,ans,temp,target,candidates);
        return ans;
    }
};