class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>st;
        for(auto it :nums)
        {
            st[it]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(st[nums[i]]==1)
            {
                return nums[i];
            }
        }
        return -1;
    }
};