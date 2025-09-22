class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        
        int ptrNums1=m-1;
        int ptrNums2=n-1;
        int i=m+n-1;
        while(ptrNums1>=0 && ptrNums2>=0)
        {
            if(nums1[ptrNums1]<nums2[ptrNums2])
            {
                nums1[i]=nums2[ptrNums2];
                ptrNums2--;
            }
            else
            {
                nums1[i]=nums1[ptrNums1];
                ptrNums1--;
            }
            i--;
        }
        while(ptrNums2>=0)
        {
            nums1[i]=nums2[ptrNums2];
            ptrNums2--;
            i--;
        }
        while(ptrNums1>=0)
        {
            nums1[i]=nums1[ptrNums1];
            ptrNums1--;
            i--;
        }    
    }
};