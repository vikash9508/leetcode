class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      //brute force approach
        // int n=nums.size();
        // vector<int>ans;
        // for(int i=0;i<n-1;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(nums[i]+nums[j]==target)
        //         {
        //            ans.push_back(i);
        //            ans.push_back(j);

        //         }
                
        //     }
        // }
        // return ans;

        //optimized approach
        unordered_map<int,int>map;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int complement=target-nums[i];
            if(map.find(complement)!=map.end())
            {
                return {map[complement],i};
            }
            map[nums[i]]=i;
        }
        return {};
    }
};