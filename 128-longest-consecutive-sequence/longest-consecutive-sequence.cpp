class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_set<int> s;
        for (int x : nums) {
            s.insert(x);
        }
        
        int longest = 0;
        for (int x : s) {
            // only start if x−1 is not present
            if (s.find(x - 1) == s.end()) {
                int curr = x;
                int streak = 1;
                
                while (s.find(curr + 1) != s.end()) {
                    curr += 1;
                    streak += 1;
                }
                
                longest = max(longest, streak);
            }
        }
        return longest;
    }
};
