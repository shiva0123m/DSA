class Solution {
public:
    bool isPalindrome(string s) 
    {
        int front=0;
        int back=s.length()-1;
        int i=0;

        while(front<back)
        {
            if(!isalnum(s[front]))
            {
                front++;
                continue;
            }
            if(!isalnum(s[back]))
            {
                back--;
                continue;
            }
            if(tolower(s[front])!=tolower(s[back]))
            {
                return false;
            }
            front++;
            back--;
        }
        return true;
    }
};