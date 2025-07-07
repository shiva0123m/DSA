class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        
        for (char digit : num) {

            while (!result.empty() && k > 0 && result.back() > digit) {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }
        
        // If there are still digits to remove, remove from the end
        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }

        // Remove leading zeros
        int nonZeroIndex = 0;
        while (nonZeroIndex < result.size() && result[nonZeroIndex] == '0') {
            nonZeroIndex++;
        }

        result = result.substr(nonZeroIndex);

        return result.empty() ? "0" : result;
    }
};
