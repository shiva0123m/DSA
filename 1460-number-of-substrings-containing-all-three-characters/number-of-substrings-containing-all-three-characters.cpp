class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0};  // count of 'a', 'b', 'c'
        int res = 0, left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            count[s[right] - 'a']++;

            // shrink window from left until it still contains all 3
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                res += s.length() - right;  // all substrings starting from `left` to `right` are valid
                count[s[left] - 'a']--;
                left++;
            }
        }
        return res;
    }
};
