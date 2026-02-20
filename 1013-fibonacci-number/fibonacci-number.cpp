class Solution {
public:
    int fibo(int n,vector<int>&dp){
        //base case
        if(n<=1)
        return n;
        //if already calculated
        if(dp[n]!=-1)
        {
            return dp[n];
        }
     return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
    }
    int fib(int n) {
        // //basic recursive method because here in question n=30
        // if(n<=1)
        // return n;
        
        // return fib(n-1)+fib(n-2);


        //if constraint aur test case change so to avoid tle we use tod down memoization
        vector<int>dp(n+1,-1);
         return fibo(n,dp);
    }
};