class Solution {
public:

    vector<int> countBits(int n) {
        vector<int>result(n+1);
     
        if(n==0)
        return result;
       for(int i=1;i<=n;i++) 
       {
        if(i%2==0){
        result[i]=result[i/2];
        }
         if(i%2!=0){
        result[i]=result[i/2]+1;
        }
       }
       return result;
    }
};