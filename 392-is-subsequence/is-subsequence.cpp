class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int sptr1=0;
        int sptr2=0;
        int l1=s.length();
        int l2=t.length();
        while(sptr1<s.length() && sptr2<t.length())
        {
            if(s[sptr1]==t[sptr2])
            {
                sptr1++;
                l1--;
            }
            sptr2++;
        }
        if(l1)
        {
            return false;
        }    
        return true;
    }
};