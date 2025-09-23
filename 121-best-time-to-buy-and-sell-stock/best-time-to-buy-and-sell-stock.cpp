class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int min_element=prices[0];
        int maxi=INT_MIN;

        for(int i=0;i<prices.size();i++)
        {
            min_element=min(min_element,prices[i]);
            maxi=max(maxi,prices[i]-min_element);
        }
        return maxi;
    }
};