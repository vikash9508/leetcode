class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixgcd(n);
        int mx=0;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,nums[i]);//space optimization
            prefixgcd[i]=gcd(nums[i],mx);
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        int i=0,j=prefixgcd.size()-1;
         long long sum=0;
        while(i<j)
        {
           sum+=gcd(prefixgcd[i],prefixgcd[j]);
           i++;
           j--;    
        }
        
       return sum;  
    }
};