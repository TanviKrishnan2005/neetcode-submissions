class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curmax =0;
        int maxsum = INT_MIN;

        for(int i =0;i<nums.size();i++){
            curmax += nums[i];
            maxsum = max(maxsum,curmax);

            if(curmax<0){
                curmax = 0;
            }
        }
        return maxsum;
    }
};
