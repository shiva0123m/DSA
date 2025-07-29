class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        int n = senate.size();

        // Fill initial queues with indices
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') radiant.push(i);
            else dire.push(i);
        }

        // Simulate rounds
        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front(); radiant.pop();
            int d = dire.front(); dire.pop();

            if (r < d) radiant.push(r + n); // Radiant acts first
            else dire.push(d + n);          // Dire acts first
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};
