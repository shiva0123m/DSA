class Solution {
public:
    int findFibonacci(int n)
    {
        if(n<=1)
        {
            return n;
        }
        return findFibonacci(n-1)+findFibonacci(n-2);
    }
    int fib(int n) 
    {
       return findFibonacci(n); 
    }
};