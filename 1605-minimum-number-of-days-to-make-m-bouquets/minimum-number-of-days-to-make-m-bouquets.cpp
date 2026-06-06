class Solution {
public:
    bool isValid(vector<int>& bloomDay, int m, int k,int mid)
    {
        int flowers=0;
        int bouquet=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=mid)
            {
                flowers++;
                if(flowers==k)
                {
                    bouquet++;
                    flowers=0;
                }
            }
            else
            {
                flowers=0;
            }
        }
        return bouquet>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int n=bloomDay.size();
        if(n<(long long)m * k)
        {
            return -1;
        }
        while(low<high)
        {
            int mid=low+(high-low)/2;

            if(isValid(bloomDay,m,k,mid))
            {
                high=mid;
            }
            else
            {
                low=mid+1;
            }  
        }
        return low;
    }
};