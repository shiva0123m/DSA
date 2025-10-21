class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                if (token == "+") st.push(b + a);
                else if (token == "-") st.push(b - a);
                else if (token == "*") st.push(b * a);
                else if (token == "/") st.push(b / a);  // integer division
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
