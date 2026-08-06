class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        int cursum =0;
        for(int x :nums){
            if(cursum<0){
                cursum = 0;
            }
            cursum += x;
            maxsum = max(maxsum,cursum);
        }
        return maxsum;
    }
};
