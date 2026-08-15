class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        bool allzero=true;
        int result=0;
        for(int x:nums)
        {
            result=result^x;
            if(x!=0)
            {
                allzero=false;
            }
        }
        if(allzero)
        return 0;

        return (result==0)?n-1:n;
    }
};