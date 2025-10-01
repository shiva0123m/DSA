class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.length();
        int wordSize = words[0].size();
        int wordCount = words.size();
        int totalLen = wordSize * wordCount;

        if (n < totalLen) return ans;

        // Build frequency map of all words
        map<string, int> wordMap;
        for (string& word : words) {
            wordMap[word]++;
        }

        // Try every offset within word size
        for (int i = 0; i < wordSize; i++) {
            int startIndex = i;
            int endIndex = i;

            map<string, int> tempMap = wordMap;
            int count = 0;

            while (endIndex + wordSize <= n) {
                string str = s.substr(endIndex, wordSize);

                if (tempMap.find(str) != tempMap.end()) {
                    tempMap[str]--;
                    if (tempMap[str] == 0) {
                        tempMap.erase(str);
                    }
                    count++;
                } else {
                    // Reset from next word after startIndex
                    startIndex += wordSize;
                    endIndex = startIndex;
                    tempMap = wordMap;
                    count = 0;
                    continue;
                }

                endIndex += wordSize;

                // If matched all words
                if (count == wordCount) {
                    ans.push_back(startIndex);

                    // Slide window forward by one word
                    string firstWord = s.substr(startIndex, wordSize);
                    tempMap[firstWord]++;
                    count--;
                    startIndex += wordSize;
                }
            }
        }

        return ans;
    }
};
