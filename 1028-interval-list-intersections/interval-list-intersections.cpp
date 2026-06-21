class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) 
    {
        int firstLength=firstList.size();
        int secondLength=secondList.size();
        vector<vector<int>>ans;
        int i=0;
        int j=0;

        while(i<firstLength && j<secondLength)
        {
            int minEnd=min(firstList[i][1],secondList[j][1]);
            int maxStart=max(firstList[i][0],secondList[j][0]);

            int isInterval=maxStart<=minEnd?1:0;

            if(isInterval)
            {
                ans.push_back({maxStart,minEnd});
            }
            
            if(firstList[i][1]<secondList[j][1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};