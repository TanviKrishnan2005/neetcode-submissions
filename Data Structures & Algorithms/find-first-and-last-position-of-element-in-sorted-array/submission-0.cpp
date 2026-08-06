class Solution {
public:

    int firstOcc(vector<int>& nums, int target){
        int i = 0;
        int j = nums.size() - 1;
        int ans = -1;

        while(i <= j){
            int mid = i + (j - i) / 2;

            if(nums[mid] == target){
                ans = mid;
                j = mid - 1;
            }
            else if(nums[mid] > target){
                j = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        return ans; 
    }

    int lastOcc(vector<int>& nums, int target){
        int i = 0;
        int j = nums.size() - 1;
        int ans = -1;

        while(i <= j){
            int mid = i + (j - i) / 2;

            if(nums[mid] == target){
                ans = mid;
                i = mid + 1;
            }
            else if(nums[mid] > target){
                j = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        return ans; 
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOcc(nums, target);
        int last = lastOcc(nums, target);
        return {first, last};
    }
};