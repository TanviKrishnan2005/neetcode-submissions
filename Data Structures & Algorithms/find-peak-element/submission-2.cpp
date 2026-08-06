class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int l = 0, r = nums.size() - 1;

        // Binary Search
        while (l < r) {

            int m = l + (r-l)/2;

            // Peak lies on the left side (including mid)
            if (nums[m] > nums[m + 1]) {
                r = m;
            }

            // Peak lies on the right side
            else {
                l = m + 1;
            }
        }

        // l == r points to a peak element
        return l;
    }
};