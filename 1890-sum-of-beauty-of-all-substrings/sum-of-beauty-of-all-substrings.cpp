#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int result = 0;

        // Step 1: Iterate through all possible substrings of s
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;
            // Step 2: Iterate through substrings starting at index i
            for (int j = i; j < n; j++) {
                freq[s[j]]++;
                
                // Step 3: Calculate the beauty of the current substring
                int maxFreq = 0, minFreq = INT_MAX;
                for (auto& entry : freq) {
                    maxFreq = max(maxFreq, entry.second);
                    minFreq = min(minFreq, entry.second);
                }
                
                // Add the beauty of this substring to the result
                result += maxFreq - minFreq;
            }
        }
        
        return result;
    }
};
