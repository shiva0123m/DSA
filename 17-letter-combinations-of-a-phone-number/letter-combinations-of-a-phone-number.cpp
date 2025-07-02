class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> phoneMap = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        string current;
        generateCombinations(digits, 0, phoneMap, current, result);
        return result;
    }

private:
    void generateCombinations(const string& digits, int index,
                              const vector<string>& phoneMap,
                              string& current, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = phoneMap[digits[index] - '0'];
        for (char letter : letters) {
            current.push_back(letter);
            generateCombinations(digits, index + 1, phoneMap, current,result);
            current.pop_back();
        }
    }
};
