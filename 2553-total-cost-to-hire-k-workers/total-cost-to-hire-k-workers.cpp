class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long total = 0;
        
        priority_queue<int, vector<int>, greater<int>> leftHeap, rightHeap;

        int i = 0, j = n - 1;

        for (int count = 0; count < candidates && i <= j; ++count) {
            leftHeap.push(costs[i++]);
        }
        for (int count = 0; count < candidates && i <= j; ++count) {
            rightHeap.push(costs[j--]);
        }

        for (int hire = 0; hire < k; ++hire) {
            if (leftHeap.empty()) {
                total += rightHeap.top(); rightHeap.pop();
                if (i <= j) rightHeap.push(costs[j--]);
            } else if (rightHeap.empty()) {
                total += leftHeap.top(); leftHeap.pop();
                if (i <= j) leftHeap.push(costs[i++]);
            } else {
                if (leftHeap.top() <= rightHeap.top()) {
                    total += leftHeap.top(); leftHeap.pop();
                    if (i <= j) leftHeap.push(costs[i++]);
                } else {
                    total += rightHeap.top(); rightHeap.pop();
                    if (i <= j) rightHeap.push(costs[j--]);
                }
            }
        }

        return total;
    }
};
