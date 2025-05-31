class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                result = mid;
                high = mid - 1;  // continue searching on the left side
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }

    int findLast(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                result = mid;
                low = mid + 1;  // continue searching on the right side
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        ans[0] = findFirst(nums, target);
        ans[1] = findLast(nums, target);
        return ans;
    }
};
