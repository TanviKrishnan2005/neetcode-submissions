class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     for(int i =0, r =0; r<nums.size();r++){
        if(nums[r]){
            swap(nums[i],nums[r]);
            i++;
            }
        }   
    }
};