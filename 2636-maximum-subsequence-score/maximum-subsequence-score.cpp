class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs(n);
        
        
        for (int i = 0; i < n; ++i) {
            pairs[i] = {nums2[i], nums1[i]};
        }

        // Sort by nums2 in descending order
        sort(pairs.rbegin(), pairs.rend());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0, result = 0;

        for (auto& [minVal, num1Val] : pairs) {
            sum += num1Val;
            minHeap.push(num1Val);

            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == k) {
                result = max(result, sum * (long long)minVal);
            }
        }

        return result;
    }
};
