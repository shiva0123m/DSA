class Solution {
public:
    int lengthOfLastWord(string s) 
    {

        istringstream iss(s);
        string word=" ";
        string lastword="";
        while(iss>>word)
        {
            lastword=word;
        }

        return lastword.length();
    }
};