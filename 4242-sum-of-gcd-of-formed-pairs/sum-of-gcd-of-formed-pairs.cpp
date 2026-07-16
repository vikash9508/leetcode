class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>mx(n);
        mx[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            mx[i]=max(mx[i-1],nums[i]);
        }
        vector<int>prefixgcd(n);
        for(int i=0;i<n;i++)
        {
            prefixgcd[i]=gcd(nums[i],mx[i]);
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        int i=0,j=n-1;
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