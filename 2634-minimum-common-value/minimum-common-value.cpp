class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        for (int i = 0; i < nums1.size(); i++) {
            int target = nums1[i];

            int start = 0;
            int end = nums2.size() - 1;

            while (start <= end) {
                int mid = start + (end - start) / 2;

                if (nums2[mid] == target) {
                    return target;
                }
                else if (nums2[mid] < target) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
