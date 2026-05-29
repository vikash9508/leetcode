class Solution {
public:
    int minElement(vector<int>& nums) {
      int n=nums.size();
      for(int i=0;i<n;i++)
      {
        int sum=0;
        while(nums[i])
        {
           sum=nums[i]%10+sum;
            nums[i]/=10;
        }
        nums[i]=sum;
      } 
      int m=INT_MAX;
      for(int i=0;i<n;i++)
      {
        m=min(m,nums[i]);
      } 
      return m;
    }
};