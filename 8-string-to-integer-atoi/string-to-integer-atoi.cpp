class Solution {
public:
    int myAtoi(string s) 
    {
        long res=0;
        int i=0;
        int sign=1;
        // removing extraspace
        while(s[i]==' ')i++;
        //checking if there is any sign in the begining 
        if(s[i]=='+' || s[i]=='-')
        {
            if(s[i]=='-')
            {
                sign=-1;
            }
            i++;
        }   
        return parseString(s,i,sign,res);
    }
    int parseString(string s,int i,int sign,long res)
    {
        if(i==s.length()|| !isdigit(s[i]))
        {
            return sign*res;
        }

        res = res * 10 + (s[i] - '0');
        if(sign*res>=INT_MAX)return INT_MAX;
        if(sign*res<=INT_MIN)return INT_MIN;

        
        return parseString(s,i+1,sign,res);
    }
};