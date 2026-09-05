class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
       int n=nums.size();
       int minel=INT_MAX;
       vector<int>minelementfromindex(n);
        for(int i=n-1;i>=0;i--)
        {
            minel=min(minel,nums[i]);
            minelementfromindex[i]=minel;
        }
        int maxel=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxel=max(maxel,nums[i]);
            if(maxel-minelementfromindex[i]<=k)
            return i;
        }
        return -1;
    }
};