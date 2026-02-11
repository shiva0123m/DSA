class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.empty()) return 0;

        int hold = -prices[0];
        int sell = 0;
        int cooldown = 0;

        for(int i = 1; i < prices.size(); i++)
        {
            int prev_hold = hold;
            int prev_sell = sell;
            int prev_cooldown = cooldown;

            hold = max(prev_hold, prev_cooldown - prices[i]);
            sell = prev_hold + prices[i];
            cooldown = max(prev_cooldown, prev_sell);
        }

        return max(sell, cooldown);
    }
};
