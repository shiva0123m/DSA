class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return 0;  // endWord must be in the wordList

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            if (word == endWord) return step;

            for (int i = 0; i < word.size(); i++) {
                char originalChar = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, step + 1});
                    }
                }
                word[i] = originalChar;
            }
        }
        return 0;
    }
};
