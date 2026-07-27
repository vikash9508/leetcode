class Solution {
public:
long long countbit(int n)
{
    long long count=0;
    while(n>0)
    {
        if((n&1)==1)
        count++;

        n=n>>1;
    }
    return count;
}
    vector<int> countBits(int n) {
        vector<int>result;
       for(int i=0;i<=n;i++) 
       {
        result.push_back(countbit(i));
       }
       return result;
    }
};