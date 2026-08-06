class Solution {
public:
    vector<vector<int>>result;
    
    void solve(vector<int>& nums,int idx , vector<int>& temp){
        //base case
        if(idx>= nums.size()){
            result.push_back(temp);
            return;
        }
        //pick
        temp.push_back(nums[idx]);
        solve(nums,idx+1,temp);

        temp.pop_back();

        //no pick
        solve(nums,idx+1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        solve(nums,0,temp);
        return result;
    }
};
