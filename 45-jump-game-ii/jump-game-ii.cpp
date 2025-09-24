class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int jump=0;
        int fastestR=0;
        int n=nums.size();
        int lastjump=0;
        for(int i=0;i<n-1;i++)
        { 
            fastestR=max(fastestR,i+nums[i]);
            if(i==lastjump)
            {
                jump++;
                lastjump=fastestR;
            }   
        }
        return jump;
    }
};