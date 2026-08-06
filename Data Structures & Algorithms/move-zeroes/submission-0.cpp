class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>no;
        vector<int>zero;
        vector<int>res;

        for(int x : nums){
            if(x!=0){
                no.push_back(x);
            }else{
                zero.push_back(x);
            }
        }

        for(int x : no){
            res.push_back(x);
        }
        for(int x :zero){
            res.push_back(x);
        }
        nums = res;
    }
};