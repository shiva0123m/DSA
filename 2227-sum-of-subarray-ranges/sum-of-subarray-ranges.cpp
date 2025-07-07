class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumOfMaxSubarrays(nums) - sumOfMinSubarrays(nums);
    }

private:
    long long sumOfMinSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n), next(n);
        stack<int> s;

        // Previous Smaller
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] > nums[i])
                s.pop();
            prev[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        // Next Smaller or Equal
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] >= nums[i])
                s.pop();
            next[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            sum += (long long)nums[i] * left * right;
        }
        return sum;
    }

    long long sumOfMaxSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n), next(n);
        stack<int> s;

        // Previous Greater
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] < nums[i])
                s.pop();
            prev[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        // Next Greater or Equal
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] <= nums[i])
                s.pop();
            next[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            sum += (long long)nums[i] * left * right;
        }
        return sum;
    }
};
