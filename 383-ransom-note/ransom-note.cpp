class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        map<char,int>mp;

        for(char i : magazine)
        {
            mp[i]++;
        }

        for(char i : ransomNote)
        {
            if(mp[i])
            {
                mp[i]--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};