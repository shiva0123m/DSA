class Solution {
public:
   vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    int n = nums.size();
    if (n == 0) return res;

    int start = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == n || nums[i] != nums[i - 1] + 1) {
            if (start == i - 1) {
                res.push_back(to_string(nums[start]));
            } else {
                res.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1]));
            }
            start = i;
        }
    }
    return res;
}
};