class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        stack<int>st;
        int n=temperatures.size();
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                st.push(i);
                ans[i]=0;
            }

            while(!st.empty() && temperatures[i]>=temperatures[st.top()])
            {
                st.pop();
            }
            if(!st.empty()&&temperatures[i]<temperatures[st.top()])
            {
                ans[i]=st.top()-i;   
            }
            if(st.empty())
            {
                ans[i]=0;
            }
            st.push(i);
        }    
        return ans;
    }
};