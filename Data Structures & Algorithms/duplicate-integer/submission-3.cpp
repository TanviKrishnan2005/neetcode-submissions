class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>set;
        for(int x : nums){
            if(set.count(x)){
                return true;
            }
            else{
                set.insert(x);
            }
        }
        return false;
    }
};