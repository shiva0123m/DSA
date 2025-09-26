class Solution {
public:
    string convert(string s, int numRows) 
    {
        int n=s.length();
        // total number of character in the section
        if(numRows==1)return s;
        
        int charinsection=2*(numRows-1); 
        string ans;
        for(int charRow=0;charRow<numRows;charRow++)
        {
            int index=charRow;

            while(index<n)
            {
                ans+=s[index];
                if(charRow!=0 && charRow!=numRows-1)
                {
                    int charIndex=charinsection- 2*(charRow);
                    int secondIndex=index+charIndex;
                    if(secondIndex<n)
                    {
                        ans+=s[secondIndex];
                    }
                }
                index+=charinsection;
            }
            
        } 
        return ans;
    }
};