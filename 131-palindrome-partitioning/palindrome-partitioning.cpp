class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>>ans;
        vector<string>paths;
        partition(0,s,ans,paths);
        return ans;    
    }
    void partition(int index,string s,vector<vector<string>>&ans,       vector<string>&paths)
    {
        if(index==s.length())
        {
            ans.push_back(paths);
            return;
        }
        for(int i=index;i<s.size();++i)
        {
            if(isPalindrome(s,index,i))
            {
                paths.push_back(s.substr(index, i - index + 1));
                partition(i+1,s,ans,paths);
                paths.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start, int end) 
    {
        while (start <= end) {
        if (s[start++] != s[end--])
            return false;
        }
        return true;
    }
};
