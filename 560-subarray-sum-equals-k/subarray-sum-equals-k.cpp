class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size(); 
        int cnt = 0; 
        int prefixsum=0;
        int remove=0;
        map<int,int>mp;
        mp[0]=1;
        for (int i = 0; i < n; i++) 
        {
            prefixsum+=nums[i];

            remove=prefixsum-k;
            cnt+=mp[remove];

            mp[prefixsum]++;

        }

        return cnt;
    }
};
