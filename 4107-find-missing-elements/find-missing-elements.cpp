class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<=nums.size()-1;i++)
        {
            st.insert(nums[i]);
        }
        int mn=nums[0];
        int mx=nums[0];
        for(int i=1;i<=nums.size()-1;i++)
        {
            if(nums[i]<mn)
            {
                mn=nums[i];
            }
            if(nums[i]>mx)
            {
                mx=nums[i];
            }
        }
        vector<int>ans;
        for(int i=mn;i<=mx;i++)
        {
            if(st.count(i)==0)
            ans.push_back(i);
        }

        return ans;
    }
};