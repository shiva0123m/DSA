class Solution {
public:
    string reverseWords(string s) 
    {
        stack<string>st;

        istringstream iss(s);
        string word;
        string ans;
        while(iss>>word)
        {
            st.push(word); 
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
            if (!st.empty()) ans += " ";  
        }
        return ans;
    }
};