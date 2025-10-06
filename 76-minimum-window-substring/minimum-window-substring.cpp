class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        if (m > n) return "";

        unordered_map<char, int> mp;
        for (char ch : t) mp[ch]++; 
        
        int count = mp.size(); 
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int startIdx = 0; 
        while (right < n) {
            char rch = s[right];

            if (mp.find(rch) != mp.end()) {
                mp[rch]--;
                if (mp[rch] == 0) {
                    count--;
                }
            }

            while (count == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                char lch = s[left];

                if (mp.find(lch) != mp.end()) {
                    mp[lch]++;
                    if (mp[lch] > 0) {
                        count++;
                    }
                }

                left++; 
            }

            right++; 
        }

        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};
