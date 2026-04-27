class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     int i=0,j=i+1,count=1;
     int n=nums.size();
     while(j<n){
        if(nums[j]==nums[j-1]){
            j++;
        }
        else{
           
            nums[i+1]=nums[j];
             j++;
             i++;
             count++;
        }
     }
     return count;   
    }
};