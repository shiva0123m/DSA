class Solution {
public:

    void formatUnevenSpaces(vector<string>& currLine, int currLen, int spaces, int maxWidth, int currIndex, int n, int unevenSpaces, vector<string>& ans) {
        string line = "";

        if (currIndex != n) {
            // Not the last line: distribute spaces evenly
            int gaps = currLine.size() - 1;
            if (gaps == 0) {
                // Only one word, left-justify
                line = currLine[0] + string(maxWidth - currLen, ' ');
            } else {
                int evenSpace = spaces / gaps;
                int extraSpaces = spaces % gaps;

                for (int i = 0; i < currLine.size(); i++) {
                    line += currLine[i];
                    if (i != currLine.size() - 1) {
                        line += string(evenSpace + (i < extraSpaces ? 1 : 0), ' ');
                    }
                }
            }
        } else {
            // Last line: left justified
            for (int i = 0; i < currLine.size(); i++) {
                line += currLine[i];
                if (i != currLine.size() - 1) line += " ";
            }
            line += string(maxWidth - line.length(), ' ');
        }

        ans.push_back(line);
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> currLine;
        int currLen = 0;
        vector<string> ans;
        int n = words.size();

        for (int currIndex = 0; currIndex < n; currIndex++) {
            string word = words[currIndex];

            if (currLen + currLine.size() + word.size() > maxWidth) {
                int totalSpaces = maxWidth - currLen;
                int unevenSpaces = totalSpaces % ((int)currLine.size() - 1 <= 0 ? 1 : currLine.size() - 1);

                formatUnevenSpaces(currLine, currLen, totalSpaces, maxWidth, currIndex, n, unevenSpaces, ans);
                currLine.clear();
                currLen = 0;
            }

            currLine.push_back(word);
            currLen += word.size();
        }

        // Last line
        if (!currLine.empty()) {
            int totalSpaces = maxWidth - currLen;
            formatUnevenSpaces(currLine, currLen, totalSpaces, maxWidth, n, n, 0, ans);
        }

        return ans;
    }
};
