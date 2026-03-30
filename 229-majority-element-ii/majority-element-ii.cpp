class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int n=nums.size();

        // Handling Base case
        if(n==0)
        {
            return nums;
        }    

        int candidate=0;
        int candidate1=1;
        int count=0;
        int count1=0;

        // Calculating candidate occurrence and ,Moore's Voting alogirthm implimentaion
        for(int i=0;i<n;i++)
        {
            if(nums[i]==candidate)
            {
                count++;
            }
            else if(nums[i]==candidate1)
            {
                count1++;
            }
            else if(count==0)
            {
                candidate=nums[i];
                count=1;
            }
            else if(count1==0)
            {
                candidate1=nums[i];
                count1++;
            }
            else
            {
                count--;
                count1--;
            }
        }

       count=0;
       count1=0;

        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==candidate)count++;
            if(nums[i]==candidate1)count1++;
        }

        vector<int>ans;

        // Cross Verification
        if(count>n/3)ans.push_back(candidate);
        if(count1>n/3)ans.push_back(candidate1);

        return ans;
    }
};