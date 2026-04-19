class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (!st.empty() && st.top() == c) {
                st.pop(); // remove duplicate
            } else {
                st.push(c); // add character
            }
        }
        
        // Build result from stack
        string result = "";
        while (!st.empty()) {
            result = st.top() + result; // reverse order
            st.pop();
        }
        
        return result;
    }
};