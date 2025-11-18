class Solution {
public:
    void generateParenthesis(vector<string>&ans,int n,string s,int ob,int cb)
    {
        if(cb==n)
        {
            ans.push_back(s);
            return;
        }
        if(ob<n)
        {
            generateParenthesis(ans,n,s+'(',ob+1,cb);
        }
        if(cb<ob)
        {
            generateParenthesis(ans,n,s+')',ob,cb+1);
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string>ans;
        string s;
        generateParenthesis(ans,n,s,0,0);
        return ans;
    }
};