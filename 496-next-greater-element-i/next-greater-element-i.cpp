class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        map<int,int> mp;
        stack<int> st;

        for(int i = 0; i < nums2.size(); i++)
        {
            while(!st.empty() && st.top() < nums2[i])
            {
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        vector<int> ans(nums1.size(), -1);
        for(int j = 0; j < nums1.size(); j++)
        {
            if(mp.find(nums1[j]) != mp.end())
            {
                ans[j] = mp[nums1[j]];
            }
        }

        return ans;
    }
};