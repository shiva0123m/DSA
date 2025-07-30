class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<pair<int, int>> sortedSpells;
        for (int i = 0; i < n; ++i) {
            sortedSpells.emplace_back(spells[i], i);
        }

        sort(sortedSpells.begin(), sortedSpells.end());
        sort(potions.begin(), potions.end());

        vector<int> result(n);
        int j = m - 1;

        for (int i = 0; i < n; ++i) {
            int spell = sortedSpells[i].first;
            int index = sortedSpells[i].second;
            while (j >= 0 && (long long)spell * potions[j] >= success) {
                --j;
            }
            result[index] = m - (j + 1);
        }

        return result;
    }
};
