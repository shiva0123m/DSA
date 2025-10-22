class Solution {
public:
    int calculate(string s) {
          stack<int> stk;
    int result = 0, currentNum = 0, sign = 1; // result holds the final answer
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];

        if (isdigit(c)) {
            currentNum = currentNum * 10 + (c - '0'); // Build the current number
        } else if (c == '+' || c == '-') {
            result += sign * currentNum; // Apply the last number
            currentNum = 0; // Reset the current number
            sign = (c == '+') ? 1 : -1; // Set the sign for the next number
        } else if (c == '(') {
            stk.push(result); // Push the current result onto the stack
            stk.push(sign); // Push the sign onto the stack
            result = 0; // Reset the result for the new expression inside parentheses
            sign = 1; // Reset sign to positive when entering parentheses
        } else if (c == ')') {
            result += sign * currentNum; // Apply the last number before closing parentheses
            currentNum = 0; // Reset current number
            result *= stk.top(); stk.pop(); // Apply the sign from the stack
            result += stk.top(); stk.pop(); // Add the previous result from the stack
        }
    }

    if (currentNum != 0) {
        result += sign * currentNum; // Apply the last number if there's any left
    }

    return result;

        
    }
};