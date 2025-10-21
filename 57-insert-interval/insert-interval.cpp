class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>>result;
        int n=intervals.size();
        int i=0;
        // Here we are skipinging  all the intervals[i][1] less than newInterval[0]
        while(i<n && intervals[i][1] < newInterval[0])
        {
            result.push_back(intervals[i]);
            i++;
        }
        // Now we intialize comparing least for newIntervals[0] and Max for newIntervals[1]
        while(i<n && intervals[i][0]<=newInterval[1])
        {
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);
            i++;
        } 
        result.push_back(newInterval);
        while(i<n)
        {
            result.push_back(intervals[i]);
            i++;
        }
        return result;   
    }
};