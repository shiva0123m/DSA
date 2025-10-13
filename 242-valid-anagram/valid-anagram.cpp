class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if (s.length() != t.length())
            return false;

        map<char, int> mp;

        for (char ch : s)
            mp[ch]++;

        for (char ch : t) {
            if (mp.count(ch) == 0 || mp[ch] == 0)
                return false;
            mp[ch]--;
        }

        // Optional final check (not strictly needed if lengths are equal and decrements are correct)
        for (auto [key, value] : mp) {
            if (value != 0)
                return false;
        }

        return true;
    }
};
