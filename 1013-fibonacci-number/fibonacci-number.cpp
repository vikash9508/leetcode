class Solution {
public:
    int fib(int n) {
        //basic recursive method because here in question n=30
        if(n<=1)
        return n;
        
        return fib(n-1)+fib(n-2);
    }
};