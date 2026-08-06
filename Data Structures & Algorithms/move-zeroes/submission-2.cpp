class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int l = 0;
        int r = 0;

        while (r < nums.size()) {

            // If current element is zero, just move r
            if (nums[r] == 0) {
                r++;
            }

            // If current element is non-zero
            else {
                swap(nums[l], nums[r]);
                l++;
                r++;
            }
        }
    }
};