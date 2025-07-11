class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        int mp_s[128]={0};
        int mp_t[128]={0};

        for(int i=0;s[i]!='\0';i++)
        {


            if(mp_s[s[i]]!=mp_t[t[i]])
            return false;
            mp_s[s[i]]=i+1;
            mp_t[t[i]]=i+1;

        }
        return true;
    }
};