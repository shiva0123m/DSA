class Solution {
public:
    int fibAns(int n)
    {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        
        return fibAns(n-1)+fibAns(n-2);
    }
    int fib(int n) 
    {
        return fibAns(n);
    }
};

// using top to bottom approach 
// with TC 2^n;