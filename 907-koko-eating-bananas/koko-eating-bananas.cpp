class Solution {
public:
    int findMax(vector<int> &v) {
        int maxi = INT_MIN;
        for (int i = 0; i < v.size(); i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    long long calculateTotalHours(vector<int> &v, int hourly) {
        long long totalH = 0; // Use long long to prevent overflow
        for (int i = 0; i < v.size(); i++) {
            totalH += (v[i] + hourly - 1LL) / hourly;  // Ensure proper 64-bit math
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = calculateTotalHours(piles, mid);  // long long here too
            if (totalH <= (long long)h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
