class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int k, int n, int start, vector<int>& path, int sum) {
        // Base cases
        if (path.size() > k || sum > n) return;

        if (path.size() == k && sum == n) {
            result.push_back(path);
            return;
        }

        for (int i = start; i <= 9; ++i) {
            path.push_back(i);
            backtrack(k, n, i + 1, path, sum + i);
            path.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        backtrack(k, n, 1, path, 0);
        return result;
    }
};
