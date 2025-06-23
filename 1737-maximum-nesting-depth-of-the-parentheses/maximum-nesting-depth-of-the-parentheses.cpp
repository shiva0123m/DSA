class Solution {
public:
    int maxDepth(string s) 
    {
        
        int counter=0;
        int maxi=INT_MIN;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')   counter++;
            if(s[i]==')')   counter--;
            maxi=max(maxi,counter);
        }   
        return maxi;
    }
};