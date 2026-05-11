class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
       vector<int>ans;
     
       for(int i=0;i<nums.size();i++){
          string s=to_string(nums[i]);
       
       for(char ch=0;ch<s.size();ch++)
        ans.push_back(s[ch]-'0');
       }
        return ans;
    }
};