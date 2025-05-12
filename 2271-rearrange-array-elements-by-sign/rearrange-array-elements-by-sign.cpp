class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        int j = 0; // Even indices for positives
        int k = 1; // Odd indices for negatives

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                arr[j] = nums[i];
                j += 2;
            } else {
                arr[k] = nums[i];
                k += 2;
            }
        }

        return arr;
    }
};
