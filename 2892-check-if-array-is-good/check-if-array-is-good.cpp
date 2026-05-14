class Solution {
public:
    bool isGood(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Maximum element should be n-1
        if(nums[n - 1] != n - 1)
            return false;

        // Check 1 to n-2
        for(int i = 0; i < n - 2; i++) {
            if(nums[i] != i + 1)
                return false;
        }

        // Last two elements must be same
        return nums[n - 1] == nums[n - 2];
    }
};