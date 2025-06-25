class Solution {
public:
    void generateparentheses(vector<string>& ans, int n, int ob, int cb, string s)
    {
        if (ob == n && cb == n) {
            ans.push_back(s); // add completed combination
            return;
        }
        if (ob < n) {
            generateparentheses(ans, n, ob + 1, cb, s + '(');
        }
        if (cb < ob) {
            generateparentheses(ans, n, ob, cb + 1, s + ')');
        }
    }

    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        generateparentheses(ans, n, 0, 0, "");
        return ans;
    }
};
