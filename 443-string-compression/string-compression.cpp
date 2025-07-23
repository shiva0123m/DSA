class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        int i = 0;

        while (i < chars.size()) {
            char current = chars[i];
            int count = 0;

            while (i < chars.size() && chars[i] == current) {
                count++;
                i++;
            }

            // Write the character
            chars[index++] = current;

            if (count > 1) {
                string cntStr = to_string(count);
                for (char c : cntStr) {
                    chars[index++] = c;
                }
            }
        }

        return index;
    }
};
