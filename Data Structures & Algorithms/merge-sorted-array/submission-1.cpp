class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // Last position to fill in nums1
        int last = m + n - 1;

        // Last valid element of nums1 and nums2
        int i = m - 1;
        int j = n - 1;

        // Merge until all elements of nums2 are placed
        while (j >= 0) {

            // Place the larger element at the end
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[last--] = nums1[i--];
            }
            else {
                nums1[last--] = nums2[j--];
            }
        }
    }
};