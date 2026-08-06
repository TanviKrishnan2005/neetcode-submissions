class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>odd,even;
        for(int i =0;i<nums.size();i++){
            if(nums[i]%2==0){
                even.push_back(nums[i]);
            }
            else{
                odd.push_back(nums[i]);
            }
        }
        vector<int>ans;
        for(int x : even){
            ans.push_back(x);
        }
        for(int x : odd){
            ans.push_back(x);
        }
        return ans;
        
    }
};