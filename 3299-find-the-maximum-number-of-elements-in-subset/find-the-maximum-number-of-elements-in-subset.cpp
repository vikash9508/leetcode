class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int>freq;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        int ans=1;
        if(freq.find(1) !=freq.end())
        {
            if(freq[1]%2==0)
            {
                ans=max(ans,freq[1]-1);
            }
            else
            {
                ans=max(ans,freq[1]);
            }
        }
        for(auto it=freq.begin();it!=freq.end();it++)
        {
            long long curr=it->first;
            if(curr==1)
            continue;
            int len=1;
            while(freq[curr]>=2 && freq.find(curr * curr)!=freq.end())
            {
                len+=2;
                curr=curr*curr;
            }
         ans=max(ans,len);
        }
           return ans;
    }
};