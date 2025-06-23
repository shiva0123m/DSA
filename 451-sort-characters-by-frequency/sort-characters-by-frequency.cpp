#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) 
    {
        
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        
        vector<pair<char, int>> freqVec(freq.begin(), freq.end());

        
        sort(freqVec.begin(), freqVec.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });

    
        string result;
        for (auto& [ch, count] : freqVec) {
            result.append(count, ch);
        }

        return result;
    }
};
