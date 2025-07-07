class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // base case: one way to have sum = 0
        int currSum = 0, result = 0;
        
        for (int num : nums) {
            currSum += num;
            if (prefixSumCount.find(currSum - goal) != prefixSumCount.end()) {
                result += prefixSumCount[currSum - goal];
            }
            prefixSumCount[currSum]++;
        }
        
        return result;
    }
};
