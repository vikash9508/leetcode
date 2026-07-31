class Solution {
public:
int rev(int x)
{
    int ans=0;
    while(x)
    {
        ans=ans*10+(x%10);
        x/=10;
    }
    return ans;
}
    int minMirrorPairDistance(vector<int>& nums) {
        int result=INT_MAX;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                result=min(result,i-mp[nums[i]]);
            }
            mp[rev(nums[i])]=i;
        
        }
        return result==INT_MAX?-1:result;

    }
};