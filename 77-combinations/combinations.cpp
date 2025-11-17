class Solution {
public:
    void findCombinations(int start,vector<vector<int>>&ans,vector<int>&temp,int n,int k)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return ;
        }

        for(int i=start;i<=n;i++)
        {
            temp.push_back(i);
            findCombinations(i+1,ans,temp,n,k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) 
    {
     vector<vector<int>>ans;
     vector<int>temp;
     findCombinations(1,ans,temp,n,k);
     return ans;   
    }
};