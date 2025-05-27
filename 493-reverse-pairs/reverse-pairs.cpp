class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left++]);
        }

        while (right <= high) {
            temp.push_back(arr[right++]);
        }

        for (int i = low; i <= high; ++i) {
            arr[i] = temp[i - low];
        }
    }

    int countPairs(vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; ++i) {
            while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        return count;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;
        int mid = (low + high) / 2;
        int count = 0;
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += countPairs(nums, low, mid, high);  // count reverse pairs
        merge(nums, low, mid, high);  // merge sorted halves
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
