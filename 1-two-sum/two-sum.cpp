class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=i;
        }

        for(int i=0;i<nums.size();i++)
        {
            int sum=target-nums[i];

            if(mp.find(sum)!=mp.end() &&
                mp[sum] != i)
            {
                return{i,mp[sum]};
            } 
        }
        return {-1,-1};
    }
};