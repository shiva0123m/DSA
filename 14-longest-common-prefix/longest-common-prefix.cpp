class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        sort(strs.begin(),strs.end());
        string ans="";
        string front=strs.front();
        string last=strs.back();

        for(int i=0;i<last.size();i++)
        {
            if(i<last.size() && front[i]==last[i])
            {
                ans+=front[i];
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};