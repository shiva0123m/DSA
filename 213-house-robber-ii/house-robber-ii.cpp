class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp1(n, -1), dp2(n, -1);

        int case1 = robRange(0, n - 2, nums, dp1);

        int case2 = robRange(1, n - 1, nums, dp2);

        return max(case1, case2);
    }

private:
    int robRange(int start, int end, vector<int>& nums, vector<int>& dp) {
        if (end < start) return 0;
        if (dp[end] != -1) return dp[end];

        return dp[end] = max(
            robRange(start, end - 1, nums, dp),
            nums[end] + robRange(start, end - 2, nums, dp)
        );
    }
};
