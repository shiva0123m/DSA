class Solution {
public:
    bool isValid(int mid,vector<int>&piles,int h)
    {
        int n=piles.size();
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=((piles[i]-1)/mid)+1;
        }
        return ans<=h?true:false;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());

        while(low<high)
        {
            int mid=low+(high-low)/2;

            if(isValid(mid,piles,h))
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