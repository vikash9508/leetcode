class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
          int n=nums.size();
          vector<int>arr1;
          vector<int>arr2;
          arr1.push_back(nums[0]);
          arr2.push_back(nums[1]);
        for(int i = 2; i < nums.size(); i++) {
        if(arr1.back() > arr2.back()) {
            arr1.push_back(nums[i]);
            }
        else {
            arr2.push_back(nums[i]);
            }
        }
          vector<int>result;
          for(int v:arr1)
          {
            result.push_back(v);
          }
           for(int v:arr2)
          {
            result.push_back(v);
          }
          return result;
    }
};