class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        stack<pair<int,int>> st; // {temperature, index}
        vector<int> ans(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++)
        {
            while(!st.empty() && temperatures[i] > st.top().first)
            {
                int index = st.top().second;
                st.pop();
                ans[index] = i - index;
            }
            st.push({temperatures[i], i});
        }

        return ans;
    }
};