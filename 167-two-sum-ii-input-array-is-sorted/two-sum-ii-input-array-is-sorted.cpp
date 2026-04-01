class Solution 
{
    public:
        vector<int> twoSum(vector<int>& numbers, int target) 
        {
            int left=0;
            int right=numbers.size()-1;

            while(left<right)
            {
                int num1=numbers[left];
                int num2=numbers[right];

                int total=num1+num2;
                if(total<target)
                {
                    left++;
                }
                else if(total>target)
                {
                    right--;
                }
                else
                {
                    return {left+1,right+1};
                }
            }
            return {};
        }
};