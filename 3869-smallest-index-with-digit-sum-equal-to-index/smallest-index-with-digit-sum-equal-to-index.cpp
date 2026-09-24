class Solution {
public:
    int smallestIndex(vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++) {

            int num = nums[i];
            int s = 0;
            while (num > 0) {
                s+= num % 10;
                num /= 10;
            }
            if (s == i) {
                return i;
            }
        }

        return -1;
    }
};