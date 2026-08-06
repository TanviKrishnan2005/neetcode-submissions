class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res =0;
        int currsum =0;
        unordered_map<int,int> prefixsum;
        prefixsum[0] =1;

        for(int num : nums){
            currsum += num;
            int diff = currsum -k;
            res += prefixsum[diff];
            prefixsum[currsum]++;
        }
        return res;
    }
};