class Solution {
    public int findFib(int n)
    {
        if(n<=1)
        {
            return n;
        }
        int first=findFib(n-1);
        int last=findFib(n-2);

        return first+last;
    }
    public int fib(int n) 
    {
        return findFib(n);
    }
}