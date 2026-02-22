class Solution {
public:
// int robber(int index,vector<int>nums,vector<int>&dp)
// {
//     if(index==0)
//     return nums[0];
//     if(index==1)
//     return max(nums[0],nums[1]);
//     if(dp[index]!=-1)
//     {
//         return dp[index];
//     }
//     return dp[index]=max(nums[index]+robber(index-2,nums,dp),robber(index-1,nums,dp));
// }
    int rob(vector<int>& nums) {

        //bottom up approach
        int n=nums.size();
        if(n==1)
        return nums[0];

        if(n==2)
        return max(nums[0],nums[1]);

        // vector<int>dp(n,-1);
        // dp[0]=nums[0];
        // dp[1]=max(nums[0],nums[1]);
        // for(int i=2;i<n;i++)
        // {
        //     dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        // }
        //  return dp[n-1];

        int curr,prev=max(nums[0],nums[1]), prev2=nums[0];
        for(int i=2;i<n;i++)
        {
            curr=max(nums[i]+prev2,prev);
            prev2=prev;
            prev=curr;
        }
        return curr; //space optimazation

    } 
};